#include "stdafx.h"
#include <iostream>
#include "attackGuai.h"
using namespace std;
attackGuai::attackGuai()
{
}
attackGuai::attackGuai(Role r, character c, bool g_gongji, bool r_gongji)
{
	
	attackGuai::r = r;
	attackGuai::c = c;
	attackGuai::g_gongji = g_gongji;
	attackGuai::r_gongji = r_gongji;
}

void attackGuai::AttackGuai()
{
	// 判断是否在角色攻击范围内
	if ((c.G.getG_x() - c.R.getRo_x() > c.R.getR_distance() / 2)) {
		r_gongji = false;
		cout << "不在攻击范围内" << endl;
	}
	if ((c.G.getG_x() - c.R.getRo_x() <= c.R.getR_distance() / 2)) {
		r_gongji = true;
		c.G.setG_xue(c.G.getG_xue() - c.R.getR_baseskill());
		r.setR_tili(c.R.getR_tili() - 5);//每次普攻消耗体力-5
		cout << "暴击！！！" << endl;
	}

	cout << c.G.getName() << "的血量剩余为" << endl;
	cout << c.R.getName() << "的体力剩余为" << endl;
	//判断怪物是否死亡
	if (c.G.getG_xue() <= 0 && c.R.getR_xue() > 0) {
		g_gongji = false;
		cout << c.G.getName() << "死亡" << endl;
		cout << "你攻击了" << c.G.getName() << "获得" << c.G.getG_exp()
			<< "经验" << endl;
		c.R.setEXP(c.R.getEXP() + c.G.getG_exp());// 击杀怪物获得经验
		l.level::Level(c,r);
		// 判断升级
		c.G.killcount++;// 击杀数量累加
		cout << "是否继续战斗？1/0?" << endl;
		int fight = 0;
		cin >> fight;
		switch (fight) {
		case 1:
			c.R.show();//打印角色信息
			c.randomMonster();//重新随机生成怪物
			break;
		case 0:
			c.R.show();//打印角色信息
			cout << "你共击败了" << c.G.killcount << "个怪物" << endl;
			break;
		}
	}
}
