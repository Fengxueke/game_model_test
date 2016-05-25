#include "stdafx.h"
#include "random.h"
#include <iostream>
#define Random(x) (rand() % x)
using namespace std;
random::random(Role r, Monster g, character c)
{
	//super();
	random::r = r;
	random::g = g;
	//random::m = m;
	random::c = c;
}

void random::randomxue()
{
	int b = Random(5) * 100;
	if (c.R.getR_xue() < 300 && b > 60 && b <= 100) {//血量少于300才会出现血瓶，且概率为五分之二
		cout << "出现血瓶！是否捡起？1或者0？" << endl;
		int ch = 0;
		cin >> ch;
		if (ch == 1) {
			c.R.setR_xue(c.R.getR_xue() + 50);
			cout << "回复生命值+50" << endl;
			cout << c.R.getName() << "的血量剩余为"
				<< c.R.getR_xue() << endl;
		}
		else {
			cout << "捡起失败！" << endl;
		}
	}
}
