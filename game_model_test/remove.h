#pragma once
#include "Role.h"
#include "Monster.h"
#include "character.h"
class Remove{
private:
	Role r;
	//Main m;
	Monster g;
	character c;
	bool g_gongji = false;
	bool r_gongji = false;
	bool canLook = false;
	int biao1 = 0;
	int biao2 = 0;
public:
	Remove(Role &r, Monster &g, character &c, bool g_gongji,
		bool r_gongji, bool canLook, int biao1, int biao2);
	character Remove_1(character &c);

};