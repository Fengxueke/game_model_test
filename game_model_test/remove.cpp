#include "stdafx.h"
#include "Remove.h"
#include <iostream>
using namespace std;
Remove::Remove(Role &R,  Monster &G, character &C, bool G_gongji, bool R_gongji, bool CanLook, int Biao1, int Biao2)
{
	r = R;
	//Remove::m = m;
	g = G;
	c = C;
	g_gongji = G_gongji;
	r_gongji = R_gongji;
	canLook = CanLook;
	biao1 = Biao1;
	biao2 = Biao2;
}

character Remove::Remove_1(character &c)
{
	//判断当前位置是否在地图里面
	if (c.R.getRo_x()<c.map.getX()) {
		if (c.R.getRo_x() > c.G.getG_x()) {
			c.R.setRo_x(c.R.getRo_x() + 50);
			if (c.R.getRo_y() > c.G.getG_y()) {
				c.R.setRo_y(c.R.getRo_y() + 50);
			}
			else {
				c.R.setRo_y(c.R.getRo_y() - 50);
			}
			if (c.R.getRo_x() - c.G.getG_x() > g.L_rect_x / 2) {
				cout << "已逃出" << c.G.getName() << "的可视范围" << endl;
				biao1 = 0;				
			}
			if (c.R.getRo_x() - c.G.getG_x() > c.R.getR_distance()) {
				cout << "已逃出" << c.G.getName() << "的攻击范围，但"
					<< c.G.getName() << "仍在靠近....." << endl;
				biao2 = 0;
			}
			return c;
		}
		else {
			c.R.setRo_x(c.R.getRo_x() - 50);
			if (c.R.getRo_y() > c.G.getG_y()) {
				c.R.setRo_y(c.R.getRo_y() + 50);
			}
			else {
				c.R.setRo_y(c.R.getRo_y() - 50);
			}
			if (c.G.getG_x() - c.R.getRo_x() > g.L_rect_x / 2) {
				cout << "已逃出" << c.G.getName() << "的可视范围" << endl;
				biao1 = 0;
				return c;
			}
			if (c.G.getG_x() - c.R.getRo_x() > c.R.getR_distance()) {
				cout << "已逃出" << c.G.getName() << "的攻击范围，但"
					<< c.G.getName() << "仍在靠近....." << endl;
				biao2 = 0;
			}

			return c;
		}
		cout << c.R.getName() << "的位置x：" << c.R.getRo_x() << " y:"
			<< c.R.getRo_y() << endl;
		cout << c.G.getName() << "的位置x：" << c.G.getG_x() << " y:"
			<< c.G.getG_y() << endl;


	}
	else {
		//否则则通关
		cout << "恭喜通关！" << endl;
		c.R.setEXP(c.R.getEXP() + c.map.getMapExp());//获得通过经验
		cout << "通过奖励：" << c.map.getMapExp() << endl;//打印经验
		g_gongji = false;
		//打印角色信息
		c.R.show();

	}
}
