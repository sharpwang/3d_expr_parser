#pragma once
#include<string>

using namespace std;

class Tag
{
public:
	enum{
		ID = 256, EQ = 257, NE = 258, LE = 259, GE = 260, ASN = 261, NUM = 262, HANZ = 263,
		LP = 264, RP = 265, //圆括号
		EOL = 266, END = 267,  //行尾,程序尾
		AND = 268, OR = 269,
		COMA = 270,
		LT = 271, GT = 272    //小于，大于
	};
};


class Token
{
public:
	int tag;

	virtual wstring tostring();
	Token();
	Token(int t);
	~Token();
};

