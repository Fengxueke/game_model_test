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
	if (c.R.getR_xue() < 300 && b > 60 && b <= 100) {//Ѫ������300�Ż����Ѫƿ���Ҹ���Ϊ���֮��
		cout << "����Ѫƿ���Ƿ����1����0��" << endl;
		int ch = 0;
		cin >> ch;
		if (ch == 1) {
			c.R.setR_xue(c.R.getR_xue() + 50);
			cout << "�ظ�����ֵ+50" << endl;
			cout << c.R.getName() << "��Ѫ��ʣ��Ϊ"
				<< c.R.getR_xue() << endl;
		}
		else {
			cout << "����ʧ�ܣ�" << endl;
		}
	}
}
