#include "stdafx.h"
#include "Parser.h"
#include "Word.h"
#include<stdexcept>
#include<exception>

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
	match(Tag::ID);
	match(Tag::ASN);
	expression();
	//env.setid(w->lexeme, expression()); 
}

void Parser::filter(){
	filter_t();
	filter_1();
}

void Parser::filter_1(){
	if (look->tag == Tag::OR){
		match(Tag::OR);
		filter_t();
		filter_1();
	}
}

void Parser::filter_e(){
	switch (look->tag){
	case Tag::LT:
		match(Tag::LT); break;
	case Tag::GT:
		match(Tag::GT); break;
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
}

void Parser::filter_f(){
	if (look->tag == Tag::LP){
		match(Tag::LP);
		filter();
		match(Tag::RP);
	}
	else{
		match(Tag::HANZ);
		filter_e();
	}
}


void Parser::filter_t(){
		filter_f();
		filter_t_1();
}

void Parser::filter_t_1(){
	if (look->tag == Tag::AND){
		match(Tag::AND);
		filter_f();
		filter_t_1();
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
	if (look->tag == L'*'){
		match(L'*');
		expression_f();
		expression_t_1();
	}
	if (look->tag == L'/'){
		match(L'/');
		expression_f();
		expression_t_1();
	}
}

void Parser::expression_1()
{
	if (look->tag == L'+'){
		match(L'+');
		expression_t();
		expression_1();
	}
	if (look->tag == L'-'){
		match(L'-');
		expression_t();
		expression_1();
	}
}

void Parser::atom()
{
	if (look->tag == Tag::ID){
		match(Tag::ID);
	}
	else if (look->tag == Tag::NUM){
		match(Tag::NUM);
	}
	else if (look->tag == Tag::HANZ){
		function();
	}
	else error(L"语法错误");
}

void Parser::function()
{
	match(Tag::HANZ);
	match(Tag::LP);
	varlist();
	match(Tag::RP);

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
