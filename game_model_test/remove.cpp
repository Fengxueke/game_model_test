#include "stdafx.h"
#include "Remove.h"
#include <iostream>
using namespace std;
Remove::Remove(Role r,  Monster g, character c, bool g_gongji, bool r_gongji, bool canLook, int biao1, int biao2)
{
	Remove::r = r;
	//Remove::m = m;
	Remove::g = g;
	Remove::c = c;
	Remove::g_gongji = g_gongji;
	Remove::r_gongji = r_gongji;
	Remove::canLook = canLook;
	Remove::biao1 = biao1;
	Remove::biao2 = biao2;
}

void Remove::Remove_1()
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
				return;
			}
			if (c.R.getRo_x() - c.G.getG_x() > c.R.getR_distance()) {
				cout << "已逃出" << c.G.getName() << "的攻击范围，但"
					<< c.G.getName() << "仍在靠近....." << endl;
				biao2 = 0;
			}
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
				return;
			}
			if (c.G.getG_x() - c.R.getRo_x() > c.R.getR_distance()) {
				cout << "已逃出" << c.G.getName() << "的攻击范围，但"
					<< c.G.getName() << "仍在靠近....." << endl;
				biao2 = 0;
			}

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
