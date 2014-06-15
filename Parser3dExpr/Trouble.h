#pragma once
#include<string>

using namespace std;

class Trouble{
private:
	wstring msg;
	Trouble();
public:
	Trouble(wstring m){ msg = m; }
	~Trouble(){};
	wstring what() {
		return msg;
	};
};
