#include "stdafx.h"
#include "Token.h"
#include <sstream>


void Token::Init()
{
	tag = 0;
	value = 0;
	state = 0;
}

Token::Token() 
{
	Init();
}

Token::Token(int t)
{
	Init();

	tag = t;
}

Token::Token(int t, wstring ws)
{
	Init();
	tag = t;
	lexeme = ws;
}

Token::Token(int t, wstring ws, int v) 
{
	Init();
	tag = t;
	lexeme = ws;
	value = v;
}


Token::~Token()
{
}

wstring Token::tostring()
{
	return lexeme;
}

