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

	Lexer lex(L"跨度 == 上期(18)&&( 十位==(百位(上期(10))+4)|| 百位 ！= 5); A:=100");
	Token* tok;
	wstring ws;
	//do{
	//	tok = lex.scan();
	//	ws = ws + tok->tostring() + L"\r\n";
	//} while (tok->tag != Tag::END);

	//wcout << ws;

	Parser parser(&lex);
	parser.statements();
	return 0;
}

