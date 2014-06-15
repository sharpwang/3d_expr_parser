#include "stdafx.h"

#include <sstream>
#include "Num.h"


Num::Num()
{
}

Num::Num(int v) :Token(Tag::NUM)
{
	value = v;
}


Num::~Num()
{
}


wstring Num::tostring()
{
	wstring ws = static_cast<wostringstream*>(&(wostringstream() << value))->str();
	wstring wstag = static_cast<wostringstream*>(&(wostringstream() << tag))->str();
	ws = ws + L"(" + wstag + L") ";
	return ws;
}