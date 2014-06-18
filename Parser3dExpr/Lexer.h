#pragma once
#include<map>
#include<string>
#include"Token.h"

using namespace std;

class Lexer
{
private:
	wchar_t peek;                   
	int pos;								//遍历source时的当前字符位置
	wstring source;
public:
	int line;								//当前字符的列的位置
	void readch();
	bool readch(wchar_t c);
	void setsource(wstring ws);
	Token scan();
	Lexer(wstring ws);
	Lexer();
	~Lexer();
};

