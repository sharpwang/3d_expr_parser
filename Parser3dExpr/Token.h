#pragma once
#include<string>

using namespace std;

class Tag
{
public:
	enum{
		ID = 256, EQ = 257, NE = 258, LE = 259, GE = 260, ASN = 261, NUM = 262, HANZ = 263,
		LP = 264, RP = 265,										//Բ����
		EOL = 266, END = 267,									//��β,����β
		AND = 268, OR = 269,
		COMA = 270,
		LT = 271, GT = 272,										//С�ڣ�����
		PLUS = 273, MINUS = 274, MULTI = 275, DIV = 276,
		FLT = 277, FNC = 278, FNC0 = 281,						//��������������޸�HANZ = 263��Token��FNC0��ʾ���������ĺ���
		DEF = 279, REF =  280,									//���������������ID = 256��Token��Ϊ�������������
		IF = 281												//�߼��ж���� ����
	};
};


class Token
{
public:
	int tag;
	wstring lexeme;
	int value;
	virtual wstring tostring();
	Token();
	Token(int t);
	Token(int t, wstring ws);
	Token(int t, wstring ws, int v);
	~Token();
};

