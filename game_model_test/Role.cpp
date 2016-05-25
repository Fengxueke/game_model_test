#include "stdafx.h"
#include "Role.h"
#include <iostream>
using namespace std;

Role::Role(string name, int r_xue, int r_tili, int r_defence, int r_baseskill, int r_distance, int EXP, int d_skill, int level)
{
	Role::name = name;
	Role::r_xue = r_xue;
	Role::r_distance = r_distance;
	Role::r_baseskill = r_baseskill;
	Role::r_defence = r_defence;
	Role::r_tili = r_tili;
	Role::EXP = EXP;
	Role::d_skill = d_skill;
	Role::level = level;
}
Role::Role()
{
}
int Role::getLevel()
{
	return level;
}

void Role::setLevel(int level)
{
	Role::level = level;
}

int Role::getR_xue()
{
	return r_xue;
}

void Role::setR_xue(int r_xue)
{
	Role::r_xue = r_xue;
}

int Role::getRo_y()
{
	return ro_y;
}

void Role::setRo_y(int ro_y)
{
	Role::ro_y = ro_y;
}

int Role::getRo_x()
{
	return ro_x;
}

void Role::setRo_x(int ro_x)
{
	Role::ro_x = ro_x;
}

int Role::getFangxiang()
{
	return fangxiang;
}

void Role::setFangxiang(int fangxiang)
{
	Role::fangxiang = fangxiang;
}

int Role::getR_baseskill()
{
	return r_baseskill;
}

void Role::setR_baseskill(int r_baseskill)
{
	Role::r_baseskill = r_baseskill;
}

int Role::getR_defence()
{
	return r_defence;
}

void Role::setR_defence(int r_defence)
{
	Role::r_defence = r_defence;
}

int Role::getR_tili()
{
	return r_tili;
}

void Role::setR_tili(int r_tili)
{
	Role::r_tili = r_tili;
}

int Role::getR_distance()
{
	return r_distance;
}

void Role::setR_distance(int r_distance)
{
	Role::r_distance = r_distance;
}

int Role::getEXP()
{
	return EXP;
}

void Role::setEXP(int eXP)
{
	EXP = eXP;
}

string Role::getName()
{
	return name;
}

void Role::setName(string name)
{
	Role::name = name;
}

int Role::getD_skill()
{
	return d_skill;
}

void Role::setD_skill(int d_skill)
{
	Role::d_skill = d_skill;
}

void Role::show()
{
	cout << getName() << "  属性值：生命：" << getR_xue() << " 体力："
		<< getR_tili() << " 防御:" << getR_defence() << " 普通攻击力："
		<< getR_baseskill() << " 攻击范围：" << getR_distance() << "目前经验："
		<< getEXP() << "目前等级" << getLevel() << endl;

}

Role::~Role()
{
}
