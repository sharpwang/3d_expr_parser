#pragma once
#include "Token.h"

class Word :
	public Token
{
private:
	Word();
public:
	wstring lexeme;

	Word(wstring s, int tag);
	virtual wstring tostring();
	virtual ~Word();
};

