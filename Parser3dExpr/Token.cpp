#include "stdafx.h"
#include "Token.h"
#include <sstream>

Token::Token()
{
}

Token::Token(int t)
{

	tag = t;
}

Token::Token(int t, wstring ws)
{
	tag = t;
	lexeme = ws;
}

Token::Token(int t, wstring ws, int v)
{
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