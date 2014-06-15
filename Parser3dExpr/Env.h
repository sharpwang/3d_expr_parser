#pragma once

#include<map>
#include<string>

using namespace std;

class Env
{
private:
	map<wstring, int> id;
public:
	void setid(wstring k, int v);
	int getid(wstring k);
	Env();
	~Env();
};

