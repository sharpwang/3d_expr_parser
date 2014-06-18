#include "stdafx.h"
#include "Env.h"
#include "Trouble.h"
#include<iostream>
#include <algorithm>

Env::Env()
{
	for (int i = 0; i < 1000; i++){
		pool[i][0] = i / 100;
		pool[i][1] = (i % 100) / 10;
		pool[i][2] = i % 10;
	}
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
	case Tag::FLT:
		flt(tok.lexeme);
		break;
	case Tag::EQ:
	case Tag::NE:
	case Tag::LE:
	case Tag::GE:
	case Tag::LT:
	case Tag::GT:
		toks.push(tok);
		break;
	case Tag::OR:
		or();
		break;
	case Tag::AND:
		and();
		break;
	case Tag::END:
		end();
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


void Env::flt(wstring ws){
	if (ws == L"个位"){
		Token tok1 = pop();
		Token tok2 = pop();
		gewei(tok1.tag, tok2.value);
	}
	else if (ws == L"十位"){
		Token tok1 = pop();
		Token tok2 = pop();
		shiwei(tok1.tag, tok2.value);
	}
	else if (ws == L"百位"){
		Token tok1 = pop();
		Token tok2 = pop();
		baiwei(tok1.tag, tok2.value);
	}
}

void Env::end(){
	set<int> v = output.top();
	for (set<int>::iterator it = v.begin(); it != v.end(); ++it)
		std::wcout <<  *it << endl;
	std::wcout << '\n';

}

void Env::or(){
	set<int> v1 = output.top(); output.pop();
	set<int> v2 = output.top(); output.pop();
	set<int> v3;
	set_union(v1.begin(), v1.end(), v2.begin(), v2.end(), inserter(v3,v3.begin()));
	output.push(v3);
}

void Env::and(){
	set<int> v1 = output.top(); output.pop();
	set<int> v2 = output.top(); output.pop();
	set<int> v3;
	set_intersection(v1.begin(), v1.end(), v2.begin(), v2.end(), inserter(v3,v3.begin()));
	output.push(v3);
}


void Env::gewei(int op, int val)
{
	set<int> v;
	for (int i = 0; i < 1000; i++){
		if (op == Tag::EQ){
			if (val == pool[i][2]){
				v.insert(i);
			}
		}
		else if (op == Tag::NE){
			if (val != pool[i][2]){
				v.insert(i);
			}
		}
		else if (op == Tag::LE){
			if (val >=  pool[i][2]){
				v.insert(i);
			}
		}
		else if (op == Tag::GE){
			if (val <=  pool[i][2]){
				v.insert(i);
			}
		}
		else if (op == Tag::LT){
			if (val >  pool[i][2]){
				v.insert(i);
			}
		}
		else if (op == Tag::GT){
			if (val <  pool[i][2]){
				v.insert(i);
			}
		}
	}
	output.push(v);
}


void Env::shiwei(int op, int val)
{
	set<int> v;
	for (int i = 0; i < 1000; i++){
		if (op == Tag::EQ){
			if (val == pool[i][1]){
				v.insert(i);
			}
		}
		else if (op == Tag::NE){
			if (val != pool[i][1]){
				v.insert(i);
			}
		}
		else if (op == Tag::LE){
			if (val >=  pool[i][1]){
				v.insert(i);
			}
		}
		else if (op == Tag::GE){
			if (val <=  pool[i][1]){
				v.insert(i);
			}
		}
		else if (op == Tag::LT){
			if (val >  pool[i][1]){
				v.insert(i);
			}
		}
		else if (op == Tag::GT){
			if (val <  pool[i][1]){
				v.insert(i);
			}
		}
	}
	output.push(v);
}


void Env::baiwei(int op, int val)
{
	set<int> v;
	for (int i = 0; i < 1000; i++){
		if (op == Tag::EQ){
			if (val == pool[i][0]){
				v.insert(i);
			}
		}
		else if (op == Tag::NE){
			if (val != pool[i][0]){
				v.insert(i);
			}
		}
		else if (op == Tag::LE){
			if (val >=  pool[i][0]){
				v.insert(i);
			}
		}
		else if (op == Tag::GE){
			if (val <=  pool[i][0]){
				v.insert(i);
			}
		}
		else if (op == Tag::LT){
			if (val >  pool[i][0]){
				v.insert(i);
			}
		}
		else if (op == Tag::GT){
			if (val <  pool[i][0]){
				v.insert(i);
			}
		}
	}
	output.push(v);
}