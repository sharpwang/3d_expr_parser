#pragma once
#include<map>
#include<string>
#include"Token.h"

using namespace std;

class Lexer
{
private:
	wchar_t peek;                   
	int pos;								//����sourceʱ�ĵ�ǰ�ַ�λ��
	wstring source;
public:
	int line;								//��ǰ�ַ����е�λ��
	void readch();
	bool readch(wchar_t c);
	void setsource(wstring ws);
	Token scan();
	Lexer(wstring ws);
	Lexer();
	~Lexer();
};

