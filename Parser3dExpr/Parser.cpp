#include "stdafx.h"
#include "Parser.h"
#include "Word.h"
#include<stdexcept>
#include<exception>
#include<iostream>

using namespace std;

Parser::Parser()
{

}

Parser::Parser(Lexer* l)
{
	lex = l;
	move();
}

Parser::~Parser()
{
}

void Parser :: move()
{
	look = lex->scan();
}

void Parser::match(int t){
	if (look->tag == t)
		move();
	else error(L"语法错误");
}


void Parser::error(wstring s) { 
	wstring es;
	es = L"在第 " + to_wstring(lex->line);
	es = es + L"行: " + s;
	throw Trouble(es);
}


void Parser::start(){
	while (look->tag != Tag::END)
	{
		stmt();
	}		
}

void Parser::stmt(){
	if (look->tag == Tag::EOL)
		match(Tag::EOL);
	else if (look->tag == Tag::ID)
		assign();
	else if (look->tag == Tag::HANZ)
		filter();
	match(Tag::EOL);
}

void Parser::assign(){
	Word* w = (Word*)look;
	Token* tok = look;
	match(Tag::ID);
	push_var(tok);
	tok = look;
	match(Tag::ASN);
	expression();
	push_var(tok);
	//env.setid(w->lexeme, expression()); 
}

void Parser::filter(){
	filter_t();
	filter_1();
}

void Parser::filter_1(){
	if (look->tag == Tag::OR){
		Token* tok = look;
		match(Tag::OR);
		filter_t();
		filter_1();
		push_var(tok);
	}
}

void Parser::filter_e(){
	Token* tok = look;
	switch (look->tag){
	case Tag::LT:
		match(Tag::LT); push_var(tok); break;
	case Tag::GT:
		match(Tag::GT); push_var(tok); break;
	case Tag::LE:
		match(Tag::LE); push_var(tok); break;
	case Tag::GE:
		match(Tag::GE); push_var(tok); break;
	case Tag::EQ:
		match(Tag::EQ); push_var(tok); break;
	case Tag::NE:
		match(Tag::NE); push_var(tok); break;
	default:
		error(L"语法错误");
	}
	expression();
}

void Parser::filter_f(){
	if (look->tag == Tag::LP){
		match(Tag::LP);
		filter();
		match(Tag::RP);
	}
	else{
		Token* tok = look;
		match(Tag::HANZ);
		filter_e();
		push_var(tok);
	}
}


void Parser::filter_t(){
		filter_f();
		filter_t_1();
}

void Parser::filter_t_1(){
	if (look->tag == Tag::AND){
		Token* tok = look;
		match(Tag::AND);
		filter_f();
		filter_t_1();
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
	if (look->tag == Tag::LP){
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
	if (look->tag == Tag::MULTI){
		Token* tok = look;
		match(Tag::MULTI);
		expression_f();
		expression_t_1();
		push_var(tok);
	}
	if (look->tag == Tag::DIV){
		Token* tok = look;
		match(Tag::DIV);
		expression_f();
		expression_t_1();
		push_var(tok);
	}
}

void Parser::expression_1()
{
	if (look->tag == Tag::PLUS){
		Token* tok = look;
		match(Tag::PLUS);
		expression_t();
		expression_1();
		push_var(tok);
	}
	if (look->tag == Tag::MINUS){
		Token* tok = look;
		match(Tag::MINUS);
		expression_t();
		expression_1();
		push_var(tok);
	}
}

void Parser::atom()
{
	if (look->tag == Tag::ID){
		Token* tok = look;
		match(Tag::ID);
		push_var(tok);
	}
	else if (look->tag == Tag::NUM){
		Token* tok = look;
		match(Tag::NUM);
		push_var(tok);
	}
	else if (look->tag == Tag::HANZ){
		function();
	}
	else error(L"语法错误");
}

void Parser::function()
{
	Token* tok = look;
	match(Tag::HANZ);
	match(Tag::LP);
	varlist();
	match(Tag::RP);
	push_var(tok);

}

void Parser::varlist()
{
	expression(); varlist_0();

}

void Parser::varlist_0()
{
	while (look->tag == Tag::COMA){
		match(Tag::COMA);
		expression();
	}
}


void Parser::statements()
{
	while (look->tag != Tag::END){
		statement();
	}
}

void Parser::statement()
{
	if (look->tag == Tag::HANZ || look->tag == Tag::LP)
		filter();
	else if (look->tag == Tag::ID)
		assign();
	else if (look->tag == Tag::EOL)
		match(Tag::EOL);
	else
		error(L"语法错误");
}

void Parser::push_var(Token* tok)
{

	wcout <<  tok->lexeme << endl;
}