#pragma once

#include"token.h"
#include<map>
#include<string>
#include<stack>

using namespace std;

class Env
{
private:
	map<wstring, int> ids;
	stack<Token> toks;
public:
	void setid(wstring k, int v);
	int getid(wstring k);
	void put(Token tok);
	Token pop();

public:
	void plus();
	void minus();
	void multi();
	void div();
	void def();
	void ref(wstring ws);
	void asn();

	Env();
	~Env();
};

