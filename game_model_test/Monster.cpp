#include "stdafx.h"
#include "Monster.h"
#include <iostream>
using namespace std;

Monster::Monster()
{
}

Monster::Monster(string name, int G_xue, string sname, int G_skill, int g_defence, int time, int distance, int killcount, int g_x, int g_y)
{
	Monster::g_x = g_x;
	Monster::g_y = g_y;
	Monster::name = name;
	Monster::g_xue = G_xue;
	Monster::sname = sname;
	Monster::g_skill = G_skill;
	Monster::g_defence = g_defence;
	Monster::time = time;
	Monster::distance = distance;
	Monster::killcount = killcount;
}

int Monster::getG_x()
{
	return g_x;
}

void Monster::setG_x(int g_x)
{
	Monster::g_x = g_x;
}

int Monster::getG_y()
{
	return g_y;
}

void Monster::setG_y(int g_y)
{
	Monster::g_y = g_y;
}

int Monster::getG_xue()
{
	return g_xue;
}

void Monster::setG_xue(int g_xue)
{
	Monster::g_xue = g_xue;
}

int Monster::getG_skill()
{
	return g_skill;
}

void Monster::setG_skill(int g_skill)
{
	Monster::g_skill = g_skill;
}

int Monster::getG_defence()
{
	return g_defence;
}

void Monster::setG_defence(int g_defence)
{
	Monster::g_defence = g_defence;
}

int Monster::getG_exp()
{
	return g_exp;
}

void Monster::setG_exp(int g_exp)
{
	Monster::g_exp = g_exp;
}

string Monster::getName()
{
	return name;
}

void Monster::setName(string name)
{
	Monster::name = name;
}

int Monster::getTime()
{
	return time;
}

void Monster::setTime(int time)
{
	Monster::time = time;
}

string Monster::getSname()
{
	return sname;
}

void Monster::setSname(string sname)
{
	Monster::sname = sname;
}

int Monster::getDistance()
{
	return distance;
}

void Monster::setDistance(int distance)
{
	Monster::distance = distance;
}

int Monster::getKillcount()
{
	return killcount;
}

void Monster::setKillcount(int killcount)
{
	Monster::killcount = killcount;
}

void Monster::show()
{
	cout << getName() << "  怪物属性值：生命： " << getG_xue() << getSname()
		<< " 伤害：" << getG_skill() << " 防御:" << getG_defence() << "  击败经验："
		<< getG_exp() << "  技能释放间隔：" << getTime() << endl;
}

