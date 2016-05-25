#pragma once
#include "level.h"
#include "Role.h"
#include "Monster.h"
#include "character.h"
class d_skill {
private:
	level l;
	static bool inCD; // ººƒ‹¿‰»¥ =false
public:
	bool isInCD();
	static void StartCD();
	static void EndCD();
	void skill(Role r, Monster g, d_skill d_skill, character c);
};