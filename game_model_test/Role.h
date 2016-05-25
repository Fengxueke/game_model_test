#pragma once
#include <string>
using namespace std;
class Role {
private:
	string name;
	int ro_x = 0;//横向坐标
	int ro_y = 0;//纵向坐标
	int fangxiang;//方向（未设置）
	int r_xue;//角色血量
	int r_distance;//角色攻击距离
	int r_baseskill;//角色基础技能
	int r_defence;//角色防御值
	int r_tili;//角色体力
	int level = 1;//角色初始等级
	int EXP;//角色经验
	int d_skill;//角色自控制技能
public:	
	Role(string name, int r_xue, int r_tili, int r_defence,
		int r_baseskill, int r_distance, int EXP, int d_skill, int level);
	Role();
	int getLevel();
	void setLevel(int level);
	int getR_xue();
	void setR_xue(int r_xue);
	int getRo_y();
	void setRo_y(int ro_y);
	int getRo_x();
	void setRo_x(int ro_x);
	int getFangxiang();
	void setFangxiang(int fangxiang);
	int getR_baseskill();
	void setR_baseskill(int r_baseskill);
	int getR_defence();
	void setR_defence(int r_defence);
	int getR_tili();
	void setR_tili(int r_tili);
	int getR_distance();
	void setR_distance(int r_distance);
	int getEXP();
	void setEXP(int eXP);
	string getName();
	void setName(string name);
	int getD_skill();
	void setD_skill(int d_skill);
	void show();
	~Role();
};