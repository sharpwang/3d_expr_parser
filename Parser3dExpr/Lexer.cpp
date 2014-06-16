#include "stdafx.h"
#include "Lexer.h"
#include "Word.h"
#include "Num.h"

using namespace std;

Lexer::Lexer()
{
}

Lexer::Lexer(std::wstring ws) :peek(L' '),line(0), pos(0)
{
	source = ws;
}

Lexer::~Lexer()
{
}

void Lexer::readch()
{
	if (pos > source.length()){
		peek = L'\0';
	}
	else if (pos == source.length()){
		peek = L'\n';
		pos = pos + 1;
	}
	else{
		peek = source.at(pos);
		pos = pos + 1;
	}
}

bool Lexer::readch(wchar_t c)
{
	readch();
	if (peek != c) return false;
	peek = L' ';
	return true;
}

Token* Lexer::scan()
{
	for (;; readch()) {
		if (peek ==  L' ' || peek == L'\t') continue;
		else 
			break;
	}

	if (peek > 0x4e00 && peek < 0x9fa5){ //4e00~9fa5是Unicode中中文汉字的编码范围
		wstring ws = L"";
		do{
			ws = ws + peek;
			readch();
		} while (peek > 0x4e00 && peek < 0x9fa5);
		Token* w = new Token(Tag::HANZ, ws);
		return w;
	}

	switch (peek)
	{
	case L':':
	case L'：':
		if (readch(L'=')) return new Token(Tag::ASN, L":=" ); else return new Token(L':'); break;
	case L'=':
		if (readch(L'=')) return new Token(Tag::EQ, L"==" ); else return new Token(L'='); break;
	case L'>':
		if (readch(L'=')) return new Token(Tag::GE, L">="); else return new Token(Tag::GT, L">"); break;
	case L'<':
		if (readch(L'=')) return new Token(Tag::LE, L"<="); else return new Token(Tag::LT, L"<"); break;
	case L'!':
	case L'！':
		if (readch(L'=')) return new Token(Tag::NE, L"!="); else return new Token(L'!'); break;
	case L'(':
	case L'（':
		peek = L' '; return new Token(Tag::LP, L"("); break;
	case L')':
	case L'）':
		peek = L' '; return new Token(Tag::RP, L")" ); break;
	case L'\n':
	case L';':
	case L'；':
		peek = L' '; line = line + 1;  return new Token( Tag::EOL, L";"); break;
	case L'|':
		if (readch(L'|')) return new Token(Tag::OR, L"||"); else return new Token(L'|'); break;
	case L'&':
		if (readch(L'&')) return new Token(Tag::AND, L"&&"); else return new Token(L'&'); break;
	case L'\0':
		return new Token(Tag::END, L"#"); break;
	case L',':
	case L'，':
		peek = L' '; return new Token(Tag::COMA, L","); break;
	case L'+':
		peek = L' '; return new Token(Tag::PLUS, L"+"); break;
	case L'-':
		peek = L' '; return new Token(Tag::MINUS, L"-"); break;
	case L'*':
		peek = L' '; return new Token(Tag::MULTI, L"*"); break;
	case L'/':
		peek = L' '; return new Token(Tag::DIV, L"/"); break;
	default:
		break;
	}

	if (peek < 256 && isdigit(peek)){
		int v = 0;
		do {
			v = 10 * v + (peek - 48); readch();
		} while (peek < 256 && isdigit(peek));
		return new Token(Tag::ID, to_wstring(v), v);
	}

	if (peek < 256 && isalpha(peek)) {
		wstring ws;
		do {
			ws = ws + peek; readch();
		} while (peek < 256 && isalpha(peek));
		Token* tok = new Token(Tag::ID, ws);
		return tok;
	}

	Token* tok = new Token(peek); peek = L' ';
	return tok;
}