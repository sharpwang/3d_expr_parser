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
		Word* w = new Word(ws, Tag::HANZ);
		words.insert(pair<wstring, Token*>(w->lexeme, w));
		return w;
	}

	switch (peek)
	{
	case L':':
	case L'：':
		if (readch(L'=')) return new Word(L":=", Tag::ASN); else return new Token(L':'); break;
	case L'=':
		if (readch(L'=')) return new Word(L"==", Tag::EQ); else return new Token(L'='); break;
	case L'>':
		if (readch(L'=')) return new Word(L">=", Tag::GE); else return new Word(L">", Tag::GT); break;
	case L'<':
		if (readch(L'=')) return new Word(L"<=", Tag::LE); else return new Word(L"<", Tag::LT); break;
	case L'!':
	case L'！':
		if (readch(L'=')) return new Word(L"!=", Tag::NE); else return new Token(L'!'); break;
	case L'(':
	case L'（':
		peek = L' '; return new Word(L"(", Tag::LP); break;
	case L')':
	case L'）':
		peek = L' '; return new Word(L")", Tag::RP); break;
	case L'\n':
	case L';':
	case L'；':
		peek = L' '; line = line + 1;  return new Word(L";", Tag::EOL); break;
	case L'|':
		if (readch(L'|')) return new Word(L"||", Tag::OR); else return new Token(L'|'); break;
	case L'&':
		if (readch(L'&')) return new Word(L"&&", Tag::AND); else return new Token(L'&'); break;
	case L'\0':
		return new Word(L"#", Tag::END); break;
	case L',':
	case L'，':
		peek = L' '; return new Word(L",", Tag::COMA); break;
	default:
		break;
	}

	if (peek < 256 && isdigit(peek)){
		int v = 0;
		do {
			v = 10 * v + (peek - 48); readch();
		} while (peek < 256 && isdigit(peek));
		return new Num(v);
	}

	if (peek < 256 && isalpha(peek)) {
		wstring ws;
		do {
			ws = ws + peek; readch();
		} while (peek < 256 && isalpha(peek));
		map<wstring, Token*>::iterator iter =  words.find(ws);
		Word* w;
		if (iter != words.end()){
			w = (Word*)iter->second;
		}
		else{
			w = new Word(ws, Tag::ID);
			words.insert(pair<wstring, Token*>(ws, w));
		}
		return w;
	}

	Token* tok = new Token(peek); peek = L' ';
	return tok;
}