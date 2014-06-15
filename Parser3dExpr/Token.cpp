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

Token::~Token()
{
}

wstring Token::tostring()
{
	wstring ws;
	ws = ws + (wchar_t)tag + L" ";
	return ws;
}