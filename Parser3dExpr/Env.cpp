#include "stdafx.h"
#include "Env.h"
#include "Trouble.h"

Env::Env()
{
}


Env::~Env()
{
}


void Env::setid(wstring k, int v)
{
	id.insert(pair<wstring, int>(k, v));
}

int Env::getid(wstring k)
{
	map<wstring, int>::iterator it = id.find(k);
	if (it == id.end()){
		throw Trouble(L"变量未定义");
	}
}