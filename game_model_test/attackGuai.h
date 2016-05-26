#pragma once
#include "Role.h"
#include "character.h"
#include "level.h"
class attackGuai {
private:
	
	Role r;
	character c;
	level l ;
	
	bool g_gongji = false;
	bool r_gongji = false;
public :
	attackGuai();
	attackGuai(Role &r, character &c, bool g_gongji, bool r_gongji);
	character AttackGuai(character &c);
};