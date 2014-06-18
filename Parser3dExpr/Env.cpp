#include "stdafx.h"
#include "Env.h"
#include "Trouble.h"
#include<iostream>

Env::Env()
{
}


Env::~Env()
{
}


void Env::setid(wstring k, int v)
{
	ids.insert(pair<wstring, int>(k, v));
	wcout << k << L":=" << v << endl;
}

int Env::getid(wstring k)
{
	map<wstring, int>::iterator it = ids.find(k);
	if (it == ids.end()){
		throw Trouble(L"变量未定义");
	} 
	return it->second;
}

void Env::put(Token tok){
	switch (tok.tag){
	case Tag::NUM:
		toks.push(tok);
		break;
	case Tag::PLUS:
		plus();
		break;
	case Tag::MINUS:
		minus();
		break;
	case Tag::MULTI:
		multi();
		break;
	case Tag::DIV:
		div();
		break;
	case Tag::DEF:
		toks.push(tok);
		break;
	case Tag::REF:
		ref(tok.lexeme);
		break;
	case Tag::ASN:
		asn();
		break;
	default:
		break;
	}
	
}

void Env::plus()
{
	Token tok1 = pop();
	Token tok2 = pop();
	int ret = tok1.value + tok2.value;
	Token tok3(Tag::NUM, to_wstring(ret), ret);
	toks.push(tok3);
}

void Env::minus()
{
	Token tok1 = pop();
	Token tok2 = pop();
	int ret = tok2.value - tok1.value;
	Token tok3(Tag::NUM, to_wstring(ret), ret);
	toks.push(tok3);
}

void Env::multi()
{
	Token tok1 = pop();
	Token tok2 = pop();
	int ret = tok2.value * tok1.value;
	Token tok3(Tag::NUM, to_wstring(ret), ret);
	toks.push(tok3);

}

void Env::div()
{
	Token tok1 = pop();
	Token tok2 = pop();
	if (tok1.value == 0){
		throw Trouble(L"除0错误");
	}
	int ret = tok2.value / tok1.value;
	Token tok3(Tag::NUM, to_wstring(ret), ret);
	toks.push(tok3);
}

void Env::def()
{

}

void Env::ref(wstring ws)
{
	int v = getid(ws);
	Token tok(Tag::NUM, to_wstring(v), v);
	toks.push(tok);
}

void Env::asn()
{
	Token tok1 = pop();
	Token tok2 = pop();
	setid(tok2.lexeme, tok1.value);

}


Token Env::pop(){
	Token tok = toks.top();
	toks.pop();
	return tok;
}

