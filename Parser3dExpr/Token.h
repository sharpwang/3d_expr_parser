#pragma once
#include<string>

using namespace std;

class Tag
{
public:
	enum{
		ID = 256, EQ = 257, NE = 258, LE = 259, GE = 260, ASN = 261, NUM = 262, HANZ = 263,
		LP = 264, RP = 265, //Բ����
		EOL = 266, END = 267,  //��β,����β
		AND = 268, OR = 269,
		COMA = 270,
		LT = 271, GT = 272    //С�ڣ�����
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

