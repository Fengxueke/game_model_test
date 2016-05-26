#include "stdafx.h"
#include "comeToGuai.h"
#include <iostream>
using namespace std;
comeToGuai::comeToGuai(Role &R, Monster &G, character &C)
{
	//继承 super();
	r = R;
	g = G;
	c = C;
}
character comeToGuai::ComeToGuai(character c)
{
	//判断当前位置是否在地图里面
		//cout << c.R.getRo_x() << endl;
		//cout << c.map.getX() << endl;
		if(c.R.getRo_x()<c.map.getX()){
		cout << "正在靠近" << c.G.getName() << endl;
		if (c.R.getRo_x() > c.G.getG_x()) {
			c.R.setRo_x(c.R.getRo_x() - 50);
			if (c.R.getRo_y() > c.G.getG_y()) {
				c.R.setRo_y(c.R.getRo_y() - 50);
			} else {
				c.R.setRo_y(c.R.getRo_y() + 50);
			}
		} else {
			c.R.setRo_x(c.R.getRo_x() + 50);
			if (c.R.getRo_y() > c.G.getG_y()) {
				c.R.setRo_y(c.R.getRo_y() - 50);
			} else {
				c.R.setRo_y(c.R.getRo_y() + 50);
			}
		}
		cout << c.R.getName() << "的位置x：" << c.R.getRo_x() << " y:"
				<< c.R.getRo_y() << endl;
		cout << c.G.getName() << "的位置x：" << c.G.getG_x() << " y:"
				<< c.G.getG_y() << endl;
		return c;
		}else{
			//否则则通关
			cout << "恭喜通关！" << endl;
			c.R.setEXP(c.R.getEXP()+c.map.getMapExp());//获取通关经验
			cout << "通过奖励：" << c.map.getMapExp() << endl;			
			c.R.show();			
		}
}
