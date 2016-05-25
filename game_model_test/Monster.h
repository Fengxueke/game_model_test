#pragma once
#include <string>
using namespace std;
class Monster {
private:
	int g_x;//横向坐标
	int g_y;//纵向坐标
	int fangxiang;//方向（未设置）
	int g_xue;//怪物血量
	int g_defence;//怪物防御值
	int g_skill;//怪物技能
	int g_exp;//击杀怪物可获取经验值
	int time;//技能冷却时间
	string name;//怪物名字
	string sname;//怪物技能名字
public:
	int distance;//攻击距离
	int killcount;//击杀总数量
	const static int L_rect_x = 300;//设置怪物初始位置 final =300
	const static int L_rect_y = 300;//设置怪物初始位置 final =300
	Monster();
	Monster(string name, int G_xue, string sname, int G_skill,
		int g_defence, int time, int distance, int killcount, int g_x, int g_y);
	int getG_x();
	void setG_x(int g_x);
	int getG_y();
	void setG_y(int g_y);
	int getG_xue();
	void setG_xue(int g_xue);
	int getG_skill();
	void setG_skill(int g_skill);
	int getG_defence();
	void setG_defence(int g_defence);
	int getG_exp();
	void setG_exp(int g_exp);
	string getName();
	void setName(string name);
	int getTime();
	void setTime(int time);
	string getSname();
	void setSname(string sname);
	int getDistance();
	void setDistance(int distance);
	int getKillcount();
	void setKillcount(int killcount);
	void show();
};