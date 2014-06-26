#pragma once

#include"token.h"
#include<map>
#include<string>
#include<stack>
#include<set>
#include<vector>

using namespace std;

class Env
{
	class Draw{
	public:
		int qh;														//ÆÚºÅ
		int sj;														//ÊÔ»úºÅ
		int kj;														//¿ª½±ºÅ
		Draw(int q, int s, int k) :qh(q), sj(s), kj(k){};
	};
private:
	map<wstring, Token> ids;
	stack<Token> toks;
	int pool[1000][3];
	stack<set<int> > output;
	vector<Draw> draws;
public:
	void loadraws();
	void setid(wstring k, Token v);
	Token getid(wstring k);
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
	void cond(Token tok);
	void fnc(wstring ws, int tag);
	void list();


	void baiwei();
	void shiwei();
	void gewei();
	void shangqi(int tag);
	void shijihao();
	void danma();

	int filter_op(wstring ws, int idx);
	Env();
	~Env();
};

