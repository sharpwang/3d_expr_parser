#pragma once
#include"Token.h"
#include"Lexer.h"
#include"Trouble.h"
#include"Env.h"
#include<string>
#include<map>
#include<stack>

using namespace std;


class Parser
{
private:
	Env env;
	Lexer lex;
	Token look;



public:
	void move();
	void match(int t);
	void start();
	void stmt();
	void assign();
	void filter();
	void filter_t();
	void filter_f();
	void filter_e();
	void filter_1();
	void filter_t_1();
	void statements();
	void statement();
	void expression();
	void expression_1();
	void expression_t();
	void expression_f();
	void expression_t_1();
	void atom();
	void function();
	void varlist();
	void varlist_0();
	void push_var(Token tok);

	void error(wstring ws);
	Parser(Lexer l);
	Parser();
	~Parser();
};
/*
filter				: filter '||' filter_t
					| filter_t
					;
filter_t			: filter_t '&&' filter_f
					| filter_f
					;
filter_f			: '(' filter ')'
					| hanzi filter_e
					;

消除左递归，如下：					
filter				: filter_t filter_1
					;
filter_1			: null
					| '||' filter_t filter_1
					;
filter_t			: filter_f filter_t_1
					;
filter_t_1			: null
					| '&&' filter_f filter_t_1
					;
filter_f			: '(' filter ')'
					| hanzi filter_e 
filter_e			: '>' expression
					| '<' expression
					| '>=' expression
					| '<=' expression
					| '==' expression
					| '!=' expression

					*/



/*
expression			: expression + expression_t
					| expression_t
					;
expression_t		: expression_t * expression_f
					| expression_f
					;
expression_f		: atom
					| '(' expression ')'
					;
					
					
消除左递归，如下：
expression			: expression_t expression_1
					;
expression_1		: null
					| '+' expression_t expression_1
					| '-' expression_t expression_1					
					;
expression_t		: expression_f expression_t_1
					;
expression_t_1		: null
					| '*' expression_f expression_t_1
					| '/' expression_f expression_t_1					
					;
expression_f		: '(' expression ')'
					| atom
					;
					*/