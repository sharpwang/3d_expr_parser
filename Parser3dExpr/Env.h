#pragma once

#include"token.h"
#include<map>
#include<string>
#include<stack>
#include<set>

using namespace std;

class Env
{
private:
	map<wstring, int> ids;
	stack<Token> toks;
	int pool[1000][3];
	stack<set<int> > output;
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
	void flt(wstring ws);
	void or();
	void and();
	void end();


	void gewei(int op, int val);											//¸öÎ»
	void shiwei(int op, int val);
	void baiwei(int op, int val);
	Env();
	~Env();
};

