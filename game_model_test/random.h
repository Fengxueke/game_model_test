#pragma once
#include "Role.h"
#include "Monster.h"
#include "character.h"
class random {
private:
	
	Role r;
	Monster g ;
	//Main m ;
	character c;
public:
	random(Role r, Monster g, character c);
	void randomxue();
};