#include "stdafx.h"
#include "Word.h"
#include <sstream>

Word::Word()
{
}

Word::Word(wstring ws, int tag):Token(tag){
	lexeme = ws;
}

Word::~Word()
{
}


wstring Word::tostring()
{
	wstring ws = lexeme;
	wstring wstag = static_cast<wostringstream*>(&(wostringstream() << tag))->str();
	ws = ws + L"(" + wstag + L") ";
	return ws;
}