#include "stdafx.h"
#include "Env.h"
#include "Trouble.h"
#include<iostream>
#include <algorithm>
#include <minmax.h>


Env::Env() 
{
	for (int i = 0; i < 1000; i++){
		pool[i][0] = i / 100;
		pool[i][1] = (i % 100) / 10;
		pool[i][2] = i % 10;
	}
	loadraws();
 }


Env::~Env()
{
}

void Env::loadraws()
{
	draws.push_back(Draw(2013320, 938, 573));
	draws.push_back(Draw(2013321, 766, 987));
	draws.push_back(Draw(2013322, 516, 648));
	draws.push_back(Draw(2013323, 938, 114));
	draws.push_back(Draw(2013324, 217, 167));
	draws.push_back(Draw(2013325, 253, 863));
	draws.push_back(Draw(2013326, 27, 233));
	draws.push_back(Draw(2013327, 281, 405));
	draws.push_back(Draw(2013328, 809, 957));
	draws.push_back(Draw(2013329, 660, 529));
	draws.push_back(Draw(2013330, 583, 4));
	draws.push_back(Draw(2013331, 709, 224));
	draws.push_back(Draw(2013332, 243, 423));
	draws.push_back(Draw(2013333, 444, 789));
	draws.push_back(Draw(2013334, 857, 680));
	draws.push_back(Draw(2013335, 352, 8));
	draws.push_back(Draw(2013336, 749, 423));
	draws.push_back(Draw(2013337, 293, 30));
	draws.push_back(Draw(2013338, 90, 517));
	draws.push_back(Draw(2013339, 321, 867));
	draws.push_back(Draw(2013340, 961, 805));
	draws.push_back(Draw(2013341, 528, 980));
	draws.push_back(Draw(2013342, 617, 899));
	draws.push_back(Draw(2013343, 157, 776));
	draws.push_back(Draw(2013344, 354, 149));
	draws.push_back(Draw(2013345, 209, 72));
	draws.push_back(Draw(2013346, 27, 19));
	draws.push_back(Draw(2013347, 392, 554));
	draws.push_back(Draw(2013348, 218, 574));
	draws.push_back(Draw(2013349, 82, 524));
	draws.push_back(Draw(2013350, 367, 322));
	draws.push_back(Draw(2013351, 16, 726));
	draws.push_back(Draw(2013352, 584, 176));
	draws.push_back(Draw(2013353, 989, 185));
	draws.push_back(Draw(2013354, 691, 24));
	draws.push_back(Draw(2013355, 825, 293));
	draws.push_back(Draw(2013356, 506, 164));
	draws.push_back(Draw(2013357, 633, 320));
	draws.push_back(Draw(2013358, 771, 968));
	draws.push_back(Draw(2014001, 196, 687));
	draws.push_back(Draw(2014002, 228, 634));
	draws.push_back(Draw(2014003, 105, 643));
	draws.push_back(Draw(2014004, 632, 955));
	draws.push_back(Draw(2014005, 624, 755));
	draws.push_back(Draw(2014006, 402, 992));
	draws.push_back(Draw(2014007, 497, 283));
	draws.push_back(Draw(2014008, 623, 590));
	draws.push_back(Draw(2014009, 211, 432));
	draws.push_back(Draw(2014010, 73, 645));
	draws.push_back(Draw(2014011, 18, 319));
	draws.push_back(Draw(2014012, 968, 368));
	draws.push_back(Draw(2014013, 871, 613));
	draws.push_back(Draw(2014014, 728, 945));
	draws.push_back(Draw(2014015, 640, 742));
	draws.push_back(Draw(2014016, 989, 224));
	draws.push_back(Draw(2014017, 92, 57));
	draws.push_back(Draw(2014018, 371, 474));
	draws.push_back(Draw(2014019, 598, 610));
	draws.push_back(Draw(2014020, 527, 87));
	draws.push_back(Draw(2014021, 985, 875));
	draws.push_back(Draw(2014022, 391, 969));
	draws.push_back(Draw(2014023, 879, 303));
	draws.push_back(Draw(2014024, 883, 344));
	draws.push_back(Draw(2014025, 458, 683));
	draws.push_back(Draw(2014026, 662, 300));
	draws.push_back(Draw(2014027, 352, 774));
	draws.push_back(Draw(2014028, 198, 805));
	draws.push_back(Draw(2014029, 744, 618));
	draws.push_back(Draw(2014030, 21, 488));
	draws.push_back(Draw(2014031, 842, 204));
	draws.push_back(Draw(2014032, 732, 256));
	draws.push_back(Draw(2014033, 452, 444));
	draws.push_back(Draw(2014034, 657, 335));
	draws.push_back(Draw(2014035, 303, 723));
	draws.push_back(Draw(2014036, 667, 630));
	draws.push_back(Draw(2014037, 205, 809));
	draws.push_back(Draw(2014038, 765, 4));
	draws.push_back(Draw(2014039, 323, 478));
	draws.push_back(Draw(2014040, 847, 68));
	draws.push_back(Draw(2014041, 898, 702));
	draws.push_back(Draw(2014042, 731, 156));
	draws.push_back(Draw(2014043, 724, 854));
	draws.push_back(Draw(2014044, 388, 585));
	draws.push_back(Draw(2014045, 570, 236));
	draws.push_back(Draw(2014046, 967, 248));
	draws.push_back(Draw(2014047, 77, 903));
	draws.push_back(Draw(2014048, 807, 214));
	draws.push_back(Draw(2014049, 552, 392));
	draws.push_back(Draw(2014050, 237, 757));
	draws.push_back(Draw(2014051, 107, 310));
	draws.push_back(Draw(2014052, 38, 793));
	draws.push_back(Draw(2014053, 86, 700));
	draws.push_back(Draw(2014054, 191, 257));
	draws.push_back(Draw(2014055, 471, 761));
	draws.push_back(Draw(2014056, 168, 386));
	draws.push_back(Draw(2014057, 805, 502));
	draws.push_back(Draw(2014058, 58, 210));
	draws.push_back(Draw(2014059, 696, 871));
	draws.push_back(Draw(2014060, 162, 977));
	draws.push_back(Draw(2014061, 825, 819));
	draws.push_back(Draw(2014062, 193, 300));
	draws.push_back(Draw(2014063, 679, 742));
	draws.push_back(Draw(2014064, 268, 361));
	draws.push_back(Draw(2014065, 114, 208));
	draws.push_back(Draw(2014066, 469, 693));
	draws.push_back(Draw(2014067, 503, 72));
	draws.push_back(Draw(2014068, 479, 968));
	draws.push_back(Draw(2014069, 649, 652));
	draws.push_back(Draw(2014070, 673, 911));
	draws.push_back(Draw(2014071, 642, 537));
	draws.push_back(Draw(2014072, 494, 662));
	draws.push_back(Draw(2014073, 135, 36));
	draws.push_back(Draw(2014074, 465, 921));
	draws.push_back(Draw(2014075, 724, 146));
	draws.push_back(Draw(2014076, 958, 559));
	draws.push_back(Draw(2014077, 666, 712));
	draws.push_back(Draw(2014078, 90, 630));
	draws.push_back(Draw(2014079, 534, 206));
	draws.push_back(Draw(2014080, 763, 670));
	draws.push_back(Draw(2014081, 703, 544));
	draws.push_back(Draw(2014082, 132, 934));
	draws.push_back(Draw(2014083, 713, 521));
	draws.push_back(Draw(2014084, 461, 558));
	draws.push_back(Draw(2014085, 75, 623));
	draws.push_back(Draw(2014086, 917, 56));
	draws.push_back(Draw(2014087, 441, 30));
	draws.push_back(Draw(2014088, 169, 404));
	draws.push_back(Draw(2014089, 840, 506));
	draws.push_back(Draw(2014090, 828, 482));
	draws.push_back(Draw(2014091, 251, 495));
	draws.push_back(Draw(2014092, 175, 303));
	draws.push_back(Draw(2014093, 969, 998));
	draws.push_back(Draw(2014094, 938, 285));
	draws.push_back(Draw(2014095, 910, 553));
	draws.push_back(Draw(2014096, 827, 738));
	draws.push_back(Draw(2014097, 97, 389));
	draws.push_back(Draw(2014098, 245, 548));
	draws.push_back(Draw(2014099, 92, 286));
	draws.push_back(Draw(2014100, 720, 170));
	draws.push_back(Draw(2014101, 380, 892));
	draws.push_back(Draw(2014102, 747, 352));
	draws.push_back(Draw(2014103, 345, 250));
	draws.push_back(Draw(2014104, 365, 957));
	draws.push_back(Draw(2014105, 219, 613));
	draws.push_back(Draw(2014106, 572, 970));
	draws.push_back(Draw(2014107, 716, 669));
	draws.push_back(Draw(2014108, 134, 960));
	draws.push_back(Draw(2014109, 445, 965));
	draws.push_back(Draw(2014110, 624, 768));
	draws.push_back(Draw(2014111, 624, 487));
	draws.push_back(Draw(2014112, 13, 429));
	draws.push_back(Draw(2014113, 850, 124));
	draws.push_back(Draw(2014114, 441, 243));
	draws.push_back(Draw(2014115, 720, 645));
	draws.push_back(Draw(2014116, 880, 910));
	draws.push_back(Draw(2014117, 382, 829));
	draws.push_back(Draw(2014118, 588, 182));
	draws.push_back(Draw(2014119, 961, 383));
	draws.push_back(Draw(2014120, 885, 758));
	draws.push_back(Draw(2014121, 638, 743));
	draws.push_back(Draw(2014122, 679, 499));
	draws.push_back(Draw(2014123, 29, 315));
	draws.push_back(Draw(2014124, 771, 701));
	draws.push_back(Draw(2014125, 16, 852));
	draws.push_back(Draw(2014126, 111, 588));
	draws.push_back(Draw(2014127, 500, 341));
	draws.push_back(Draw(2014128, 24, 780));
	draws.push_back(Draw(2014129, 834, 145));
	draws.push_back(Draw(2014130, 19, 211));
	draws.push_back(Draw(2014131, 669, 870));
	draws.push_back(Draw(2014132, 925, 139));
	draws.push_back(Draw(2014133, 191, 650));
	draws.push_back(Draw(2014134, 921, 85));
	draws.push_back(Draw(2014135, 67, 409));
	draws.push_back(Draw(2014136, 140, 840));
	draws.push_back(Draw(2014137, 895, 169));
	draws.push_back(Draw(2014138, 499, 587));
	draws.push_back(Draw(2014139, 870, 764));
	draws.push_back(Draw(2014140, 961, 901));
	draws.push_back(Draw(2014141, 658, 921));
	draws.push_back(Draw(2014142, 111, 594));
	draws.push_back(Draw(2014143, 826, 244));
	draws.push_back(Draw(2014144, 655, 77));
	draws.push_back(Draw(2014145, 553, 612));
	draws.push_back(Draw(2014146, 245, 367));
	draws.push_back(Draw(2014147, 82, 578));
	draws.push_back(Draw(2014148, 704, 180));
	draws.push_back(Draw(2014149, 484, 262));
	draws.push_back(Draw(2014150, 578, 107));
	draws.push_back(Draw(2014151, 325, 391));
	draws.push_back(Draw(2014152, 200, 821));
	draws.push_back(Draw(2014153, 950, 392));
	draws.push_back(Draw(2014154, 65, 115));
	draws.push_back(Draw(2014155, 688, 677));
	draws.push_back(Draw(2014156, 195, 419));
	draws.push_back(Draw(2014157, 337, 575));
	draws.push_back(Draw(2014158, 535, 411));
	draws.push_back(Draw(2014159, 118, 312));
	draws.push_back(Draw(2014160, 903, 45));
	draws.push_back(Draw(2014161, 986, 946));
}
void Env::setid(wstring k, Token v)
{
	ids.insert(pair<wstring, Token>(k, v));
//	wcout << k << L":=" << v << endl;
}

Token Env::getid(wstring k)
{
	map<wstring, Token>::iterator it = ids.find(k);
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
		cond(tok);
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
	case Tag::FNC:
	case Tag::FNC0:
		fnc(tok.lexeme, tok.tag);
		break;
	case Tag::LBRK:
		toks.push(tok);
		break;
	case Tag::RBRK:
		list();
	default:
		break;
	}
	
}

void Env::list()
{
	Token tok = pop();
	vector<Token> vtemp ;
	while (tok.tag != Tag::LBRK){
		vtemp.push_back(tok);
		tok = pop();
	}
	Token temp(Tag::LIST);
	while (vtemp.size()){
		temp.children.push_back(vtemp.at(vtemp.size() - 1));
		vtemp.pop_back();
	}
	toks.push(temp);
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
	Token v = getid(ws);
	toks.push(v);
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
	Token tok1 = pop();
	Token tok2 = pop();
	set<int> v;
	for (int i = 0; i < 1000; i++){
		if (tok1.tag == Tag::EQ){
			if (tok2.value == filter_op(ws, i)){
				v.insert(i);
			}
		}
		else if (tok1.tag == Tag::NE){
			if (tok2.value != filter_op(ws, i)){
				v.insert(i);
			}
		}
		else if (tok1.tag == Tag::LE){
			if (tok2.value >= filter_op(ws, i)){
				v.insert(i);
			}
		}
		else if (tok1.tag == Tag::GE){
			if (tok2.value <= filter_op(ws, i)){
				v.insert(i);
			}
		}
		else if (tok1.tag == Tag::LT){
			if (tok2.value > filter_op(ws, i)){
				v.insert(i);
			}
		}
		else if (tok1.tag == Tag::GT){
			if (tok2.value < filter_op(ws, i)){
				v.insert(i);
			}
		}
	}
	output.push(v);
}

void Env::fnc(wstring ws, int tag)
{
	if (ws == L"百位")
		baiwei();
	else if (ws == L"十位")
		shiwei();
	else if (ws == L"个位")
		gewei();
	else if (ws == L"上期")
		shangqi(tag);
	else if (ws == L"试机号" || ws == L"试机")
		shijihao();
}

void Env::baiwei()
{
	Token tok = pop();
	tok.value = tok.value / 100;
	put(tok);
}

void Env::shiwei()
{
	Token tok = pop();
	tok.value = (tok.value % 100) / 10;
	put(tok);
}

void Env::gewei()
{
	Token tok = pop();
	int value = tok.value % 10;
	Token tok2(Tag::NUM, to_wstring(value), value);
	put(tok2);
}

void Env::shangqi(int tag)
{
	int len = draws.size();
	int ref = 1;
	if (tag == Tag::FNC){
		Token tok = pop();
		ref = tok.value;
	}
	int value = draws[len - ref].kj;
	Token tok(Tag::NUM, to_wstring(value), value);
	put(tok);
}

void Env::shijihao()
{
	int len = draws.size();
	Token tok = pop();
	int ref = tok.value;
	int value = draws[len - ref].sj;
	Token tok2(Tag::NUM, to_wstring(value), value);
	put(tok2);
}

int Env::filter_op(wstring ws, int idx)
{
	if (ws == L"个位"){
		return pool[idx][2];
	}
	else if (ws == L"十位"){
		return pool[idx][1];
	}
	else if (ws == L"百位"){
		return pool[idx][0];
	}
	else if (ws == L"和值"){
		return pool[idx][0] + pool[idx][1] + pool[idx][2];
	}
	else if (ws == L"和尾"){
		return (pool[idx][0] + pool[idx][1] + pool[idx][2]) % 10;
	}
	else if (ws == L"号码"){
		return pool[idx][0] * 100 + pool[idx][1] * 10 + pool[idx][2];
	}
	else if (ws == L"跨度" || ws == L"跨距"){
		return max(max(pool[idx][0], pool[idx][1]), pool[idx][2]) - min(min(pool[idx][0], pool[idx][1]), pool[idx][2]);
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

void Env::cond(Token tok){
	if (tok.InFilt()) {
		toks.push(tok);
		return;
	}
	else{															//tok.InCond() == true
		Token tok1 = pop();
		Token tok2 = pop();
		int value = 0;
		switch (tok.tag){
			case Tag::EQ:
				value = tok2.value == tok1.value; break;
			case Tag::NE:
				value = tok2.value != tok1.value; break;
			case Tag::LE:
				value = tok2.value <= tok1.value; break;
			case Tag::GE:
				value = tok2.value >= tok1.value; break;
			case Tag::LT:
				value = tok2.value < tok1.value; break;
			case Tag::GT:
				value = tok2.value > tok1.value; break;
			default:
				throw Trouble(L"非法比较符");
		}
		toks.push(Token(tok.tag, to_wstring(value), value));
		return;
	}
}