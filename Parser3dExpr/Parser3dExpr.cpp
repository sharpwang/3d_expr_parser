// Parser3dExpr.cpp : �������̨Ӧ�ó������ڵ㡣
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

	Lexer lex(L"��� == ����(18)&&( ʮλ==(��λ(����(10))+4)|| ��λ ��= 5); A:=100");
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

