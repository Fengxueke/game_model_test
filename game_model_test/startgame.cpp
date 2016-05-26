#include "stdafx.h"
#include "startgame.h"
#include <iostream>
#include <Windows.h>
using namespace std;
startgame::startgame(Role &R, Monster &G, character &C, bool G_gongji, bool R_gongji, bool CanLook, int Biao1, int Biao2)
{
	r = R;
	//startgame::m = m;
	g = G;
	c = C;
	g_gongji = G_gongji;
	r_gongji = R_gongji;
	canLook = CanLook;
	biao1 = Biao1;
	biao2 = Biao2;
}

character startgame::ai(character &c)
{
	if (c.R.getRo_x() > c.G.getG_x()) {
		if ((c.R.getRo_x() - c.G.getG_x() > g.L_rect_x / 2)) {
			// 逃出可视范围
			canLook = false;
			g_gongji = false;
			
		}
		if ((c.R.getRo_x() - c.G.getG_x() <= g.L_rect_x / 2)) {
			// 进入可视范围
			canLook = true;
			c.G.setG_x(c.G.getG_x() + 15);
			if (c.R.getRo_y() > c.G.getG_y()) {
				c.G.setG_y(c.G.getG_y() + 15);
			}
			else {
				c.G.setG_y(c.G.getG_y() - 15);
			}
		}
		if ((c.R.getRo_x() - c.G.getG_x() > c.G.distance / 2)) {
			// 逃出攻击范围
			g_gongji = false;
			
		}
		if ((c.R.getRo_x() - c.G.getG_x() <= c.G.distance / 2)) {
			// 进入攻击范围

			// 攻击c.c.R.getName()
			g_gongji = true;
		}

	}
	else {
		if ((c.G.getG_x() - c.R.getRo_x()) > g.L_rect_x / 2) {
			// 逃出可视范围
			canLook = false;
			g_gongji = false;
			
		}
		if ((c.G.getG_x() - c.R.getRo_x() <= g.L_rect_x / 2)) {
			// 进入可视范围
			canLook = true;

			c.G.setG_x(c.G.getG_x() - 15);
			if (c.R.getRo_y() > c.G.getG_y()) {
				c.G.setG_y(c.G.getG_y() + 15);
			}
			else {
				c.G.setG_y(c.G.getG_y() - 15);
			}
		}

		if ((c.G.getG_x() - c.R.getRo_x() > c.G.distance / 2)) {
			// 逃出攻击范围
			g_gongji = false;
			
		}

		if ((c.G.getG_xue() > 0 && c.G.getG_x() - c.R.getRo_x() <= c.G.distance / 2)) {
			// 进入攻击范围

			// 攻击c.c.R.getName()
			g_gongji = true;

		}

	}
	return c;
}

character startgame::start(character &c)
{
	while (1>0) {
		try {
			cout << "角色位置-->" << c.R.getRo_x() << "  怪的位置-->" << c.G.getG_x() << endl;
			//Thread.sleep(1000);
			Sleep(1000);
			if (c.R.getR_xue() > 0 && c.G.getG_xue()>0) {
				ai(c);
				//cout << c.R.getRo_x() << endl;
				//return c;
			}
			if (canLook && biao1 == 0 && c.G.getG_xue()>0) {
				biao1 = 1;
				cout << "已进入" + c.G.getName() + "的可视范围,"
					+ c.G.getName() + "正在靠近....." << endl;
				//return c;
			}
			while (c.R.getR_xue() > 0 && g_gongji&&c.G.getG_xue()>0) {
				if (g_gongji && biao2 == 0) {
					biao2 = 2;
					cout << "已进入" + c.G.getName() + "的攻击范围,"
						+ c.G.getName() + "正在攻击...." << endl;
				}
				Sleep(c.G.getTime());
				c.R.setR_xue(c.R.getR_xue() - c.G.getG_skill()
					+ c.R.getR_defence() / 5);
				if (c.G.getG_xue()>0) {
					ai(c);
				}
				// m.attackGuai(r, g);
				cout << c.G.getName() + "正在攻击，释放技能："
					<< c.G.getSname() << endl;
				cout << c.R.getName() + "的血量剩余为"
					<< c.R.getR_xue() << endl;
				if (c.R.getR_xue() <= 0) {
					cout << "玩家死亡！游戏结束！" << endl;
					cout << "你共击败了" + c.G.killcount << "个怪物！" << endl;
					//system("pause");
				}
				if (c.G.getG_xue() <= 0) {
					cout << c.G.getName() + "死亡！" << endl;
					break;
				}
			}

		}

		catch (...) {
               //
		}
	}
	//return c;
}

startgame::startgame()
{
}
