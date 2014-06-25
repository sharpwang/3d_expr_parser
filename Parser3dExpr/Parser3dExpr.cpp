// Parser3dExpr.cpp : 定义控制台应用程序的入口点。
//


#include "stdafx.h"
#include "Lexer.h"
#include "Parser.h"
#include<string>
#include<iostream>
using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	setlocale(LC_ALL, "chs");

	Lexer lex(L"假如( 百位(上期) == 9 , A:= 1)");
	wstring ws;
	//do{
	//	tok = lex.scan();
	//	ws = ws + tok->tostring() + L"\r\n";
	//} while (tok->tag != Tag::END);

	//wcout << ws;

	Parser parser(lex);
	parser.statements();
	return 0;
}

/*		ID = 256, EQ = 257, NE = 258, LE = 259, GE = 260, ASN = 261, NUM = 262, HANZ = 263,
		LP = 264, RP = 265, //圆括号
		EOL = 266, END = 267,  //行尾,程序尾
		AND = 268, OR = 269,
		COMA = 270,
		LT = 271, GT = 272    //小于，大于
		
*/