#pragma once
#include "Role.h"
#include "Monster.h"
#include "character.h"
#include "attackGuai.h"
class startgame {
private:
	Role r;
	//Main m;
	Monster g;
	character c;
	attackGuai atk;
	bool g_gongji = false;
	bool r_gongji = false;
	bool canLook = false;
	int biao1 = 0;
	int biao2 = 0;
public:
	startgame(Role r,  Monster g, character c, bool g_gongji,
		bool r_gongji, bool canLook, int biao1, int biao2);
	void ai(character c);
	void start();
	startgame();
};