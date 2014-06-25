#include "stdafx.h"
#include "Parser.h"
#include<stdexcept>
#include<exception>
#include<iostream>

using namespace std;

Parser::Parser() :skip_mode(false)
{

}

Parser::Parser(Lexer l) : skip_mode(false), lex(l)
{
	move();
}

Parser::~Parser()
{
}

void Parser :: move()
{
	look = lex.scan();
}

void Parser::match(int t){
	if (look.tag == t)
		move();
	else error(L"语法错误");
}


void Parser::error(wstring s) { 
	wstring es;
	es = L"在第 " + to_wstring(lex.line);
	es = es + L"行: " + s;
	throw Trouble(es);
}


void Parser::assign(){
	Token tok1 = look;
	match(Tag::ID);
	tok1.tag = Tag::DEF;												//重新定义Token的Tag属性，这是一个变量的定义
	push_var(tok1);
	Token tok2 = look;
	match(Tag::ASN);
	condition();
	push_var(tok2);

	//env.setid(w->lexeme, expression()); 
}

void Parser::filter(){
	filter_t();
	filter_1();
}

void Parser::filter_1(){
	if (look.tag == Tag::OR){
		Token tok = look;
		match(Tag::OR);
		filter_t();
		filter_1();
		tok.IntoFilt();
		push_var(tok);
	}
}

void Parser::filter_e(){
	Token tok = look;
	switch (look.tag){
	case Tag::LT:
		match(Tag::LT); break;
	case Tag::GT:
		match(Tag::GT);  break;
	case Tag::LE:
		match(Tag::LE); break;
	case Tag::GE:
		match(Tag::GE); break;
	case Tag::EQ:
		match(Tag::EQ); break;
	case Tag::NE:
		match(Tag::NE); break;
	default:
		error(L"语法错误");
	}
	expression();
	tok.IntoFilt();
	push_var(tok);

}

void Parser::filter_f(){
	if (look.tag == Tag::LP){
		match(Tag::LP);
		filter();
		match(Tag::RP);
	}
	else{
		Token tok = look;
		match(Tag::HANZ);
		filter_e();
		tok.tag = Tag::FLT;												//重新定义Token的Tag属性，这是一个过滤条件
		push_var(tok);
	}
}


void Parser::filter_t(){
		filter_f();
		filter_t_1();
}

void Parser::filter_t_1(){
	if (look.tag == Tag::AND){
		Token tok = look;
		match(Tag::AND);
		filter_f();
		filter_t_1();
		tok.IntoFilt();
		push_var(tok);
	}

}

void Parser::condition()
{
	condition_t();
	condition_1();
}

void Parser::condition_t()
{
	condition_f();
	condition_t_1();

}

void Parser::condition_f()
{
	if (look.tag == Tag::LP){
		match(Tag::LP);
		condition();
		match(Tag::RP);
	}
	else{
		condition_e();
	}

}

void Parser::condition_e()
{
	expression();
	Token tok = look;
	switch (look.tag){
	case Tag::LT:
		match(Tag::LT); break;
	case Tag::GT:
		match(Tag::GT);  break;
	case Tag::LE:
		match(Tag::LE); break;
	case Tag::GE:
		match(Tag::GE); break;
	case Tag::EQ:
		match(Tag::EQ); break;
	case Tag::NE:
		match(Tag::NE); break;
	default:
		return;														//error(L"语法错误"); 
																	/*注释掉上一句是因为允许一个条件就是一个表达式，只不过这个条件的值等于表达式的值
																	这样，一个条件语句返回的就可以是任何数值，而不仅仅是0或者1*/
	}
	expression();
	tok.IntoCond();
	push_var(tok);
}

void Parser::condition_1()
{
	if (look.tag == Tag::OR){
		Token tok = look;
		match(Tag::OR);
		condition_t();
		condition_1();
		tok.InCond();
		push_var(tok);
	}

}

void Parser::condition_t_1()
{
	if (look.tag == Tag::AND){
		Token tok = look;
		match(Tag::AND);
		condition_f();
		condition_t_1();
		tok.InCond();
		push_var(tok);
	}
}

void Parser::expression()
{
	expression_t();
	expression_1();
}

void Parser::expression_f()
{
	if (look.tag == Tag::LP){
		match(Tag::LP);
		expression();
		match(Tag::RP);
	}
	else{
		atom();
	}
}

void Parser::expression_t()
{
	expression_f();
	expression_t_1();

}

void Parser::expression_t_1()
{
	if (look.tag == Tag::MULTI){
		Token tok = look;
		match(Tag::MULTI);
		expression_f();
		expression_t_1();
		push_var(tok);
	}
	if (look.tag == Tag::DIV){
		Token tok = look;
		match(Tag::DIV);
		expression_f();
		expression_t_1();
		push_var(tok);
	}
}

void Parser::expression_1()
{
	if (look.tag == Tag::PLUS){
		Token tok = look;
		match(Tag::PLUS);
		expression_t();
		expression_1();
		push_var(tok);
	}
	if (look.tag == Tag::MINUS){
		Token tok = look;
		match(Tag::MINUS);
		expression_t();
		expression_1();
		push_var(tok);
	}
}


void Parser::atom()
{
	if (look.tag == Tag::ID){
		Token tok = look;
		match(Tag::ID);
		tok.tag = Tag::REF;												//重新定义Token的Tag属性，这是一个变量的引用
		push_var(tok);
	}
	else if (look.tag == Tag::NUM){
		Token tok = look;
		match(Tag::NUM);
		push_var(tok);
	}
	else if (look.tag == Tag::HANZ){
		function();
	}
	else error(L"语法错误");
}

void Parser::function()
{
	Token tok = look;
	match(Tag::HANZ);
	tok.tag = Tag::FNC0;												//重新定义Token的Tag属性，这是一个不带参数的函数。
	if (look.tag == Tag::LP){											//这样就支持了不带参数的函数
		tok.tag = Tag::FNC;												//这是一个带有参数的函数
		match(Tag::LP);
		varlist();
		match(Tag::RP);
	}
																		//重新定义Token的Tag属性，这是一个函数。
	push_var(tok);

}

void Parser::varlist()
{
	expression(); varlist_0();

}

void Parser::varlist_0()
{
	while (look.tag == Tag::COMA){
		match(Tag::COMA);
		expression();
	}
}

void Parser::set_skip_mode()
{
	skip_mode = false;
	for (int i = 0; i < conds.size(); i++)
	{
		if (conds.at(i).value == 0) skip_mode = true;
	}
}

void Parser::ifthen()
{
	match(Tag::IF);
	match(Tag::LP);
	condition();
	match(Tag::COMA);
	conds.push_back(env.pop());
	set_skip_mode();
	statement_1();
	conds.pop_back();
	set_skip_mode();
	match(Tag::RP);
}


void Parser::statements()
{
	while (look.tag != Tag::END){
		statement();
	}
	push_var(look);
}

void Parser::statement_1()
{
	if (look.tag == Tag::HANZ || look.tag == Tag::LP)
		filter();
	else if (look.tag == Tag::ID)
		assign();
	else if (look.tag == Tag::IF)
		ifthen();
	else
		error(L"语法错误");
}

void Parser::statement()
{
	if (look.tag == Tag::EOL)
		match(Tag::EOL);
	else
		statement_1();
}

void Parser::push_var(Token tok)
{
	wcout << tok.lexeme << endl;
	if (skip_mode == false)
		env.put(tok);
}