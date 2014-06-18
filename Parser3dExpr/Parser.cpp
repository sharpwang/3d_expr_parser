#include "stdafx.h"
#include "Parser.h"
#include<stdexcept>
#include<exception>
#include<iostream>

using namespace std;

Parser::Parser()
{

}

Parser::Parser(Lexer l)
{
	lex = l;
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
	else error(L"�﷨����");
}


void Parser::error(wstring s) { 
	wstring es;
	es = L"�ڵ� " + to_wstring(lex.line);
	es = es + L"��: " + s;
	throw Trouble(es);
}


void Parser::assign(){
	Token tok1 = look;
	match(Tag::ID);
	tok1.tag = Tag::DEF;												//���¶���Token��Tag���ԣ�����һ�������Ķ���
	push_var(tok1);
	Token tok2 = look;
	match(Tag::ASN);
	expression();
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
		error(L"�﷨����");
	}
	expression();
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
		tok.tag = Tag::FLT;												//���¶���Token��Tag���ԣ�����һ����������
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
		tok.tag = Tag::REF;												//���¶���Token��Tag���ԣ�����һ������������
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
	else error(L"�﷨����");
}

void Parser::function()
{
	Token tok = look;
	match(Tag::HANZ);
	match(Tag::LP);
	varlist();
	match(Tag::RP);
	tok.tag = Tag::FNC;													//���¶���Token��Tag���ԣ�����һ��������
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


void Parser::statements()
{
	while (look.tag != Tag::END){
		statement();
	}
	push_var(look);
}

void Parser::statement()
{
	if (look.tag == Tag::HANZ || look.tag == Tag::LP)
		filter();
	else if (look.tag == Tag::ID)
		assign();
	else if (look.tag == Tag::EOL)
		match(Tag::EOL);
	else
		error(L"�﷨����");
}

void Parser::push_var(Token tok)
{
	wcout << tok.lexeme << endl;
	env.put(tok);

}