#pragma once
#include<string>
#include<vector>

using namespace std;

class Tag
{
public:
	enum{
		ID = 256, EQ = 257, NE = 258, LE = 259, GE = 260, ASN = 261, NUM = 262, HANZ = 263,
		LP = 264, RP = 265,										//圆括号
		EOL = 266, END = 267,									//行尾,程序尾
		AND = 268, OR = 269,
		COMA = 270,
		LT = 271, GT = 272,										//小于，大于
		PLUS = 273, MINUS = 274, MULTI = 275, DIV = 276,
		FLT = 277, FNC = 278, FNC0 = 281,						//根据语义分析，修改HANZ = 263的Token，FNC0表示不带参数的函数
		DEF = 279, REF =  280,									//根据语义分析，把ID = 256的Token分为定义项和引用项
		IF = 281,												//逻辑判断语句 假如
		LBRC = 282, RBRC = 283,									//大括号 brace {}
		LIST = 284
	};
};


class Token
{
private:
	void Init();
public:
	enum{ COND = 11, FILT = 22 };
	int tag;
	wstring lexeme;
	int value;
	int state;													//标明当前符号所在的语句状态； CND 或者 FLT
	vector<Token> children;
	virtual wstring tostring();
	Token();
	Token(int t);
	Token(int t, wstring ws);
	Token(int t, wstring ws, int v);
	inline void IntoCond(){ state = COND; }
	inline void IntoFilt(){ state = FILT; }
	inline bool InCond(){ return state == COND; }
	inline bool InFilt(){ return state == FILT; }
	~Token();
};

