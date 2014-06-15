#pragma once
#include "Token.h"
class Num :
	public Token
{
private:
	Num();
public:
	int value;
	Num(int v);
	virtual wstring tostring();
	virtual ~Num();
};

