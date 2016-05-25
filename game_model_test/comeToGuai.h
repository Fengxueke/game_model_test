#pragma once
#include "Role.h"
#include "Monster.h"
#include "character.h"
class comeToGuai {
private:
	
	Role r;
	Monster g ;
	character c;
	
public :
	comeToGuai(Role& r, Monster& g, character& c);
	//comeToGuai(comeToGuai& ct);
	void ComeToGuai();
};