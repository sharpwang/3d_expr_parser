#include "stdafx.h"
#include "Token.h"
#include <sstream>


Token::Token() :tag(0), value(0), state(0)
{
}

Token::Token(int t):tag(0), value(0), state(0)
{

	tag = t;
}

Token::Token(int t, wstring ws) : value(0), state(0)
{
	tag = t;
	lexeme = ws;
}

Token::Token(int t, wstring ws, int v) :state(0)
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