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
	//�жϵ�ǰλ���Ƿ��ڵ�ͼ����
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
				cout << "���ӳ�" << c.G.getName() << "�Ŀ��ӷ�Χ" << endl;
				biao1 = 0;
				return;
			}
			if (c.R.getRo_x() - c.G.getG_x() > c.R.getR_distance()) {
				cout << "���ӳ�" << c.G.getName() << "�Ĺ�����Χ����"
					<< c.G.getName() << "���ڿ���....." << endl;
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
				cout << "���ӳ�" << c.G.getName() << "�Ŀ��ӷ�Χ" << endl;
				biao1 = 0;
				return;
			}
			if (c.G.getG_x() - c.R.getRo_x() > c.R.getR_distance()) {
				cout << "���ӳ�" << c.G.getName() << "�Ĺ�����Χ����"
					<< c.G.getName() << "���ڿ���....." << endl;
				biao2 = 0;
			}

		}
		cout << c.R.getName() << "��λ��x��" << c.R.getRo_x() << " y:"
			<< c.R.getRo_y() << endl;
		cout << c.G.getName() << "��λ��x��" << c.G.getG_x() << " y:"
			<< c.G.getG_y() << endl;


	}
	else {
		//������ͨ��
		cout << "��ϲͨ�أ�" << endl;
		c.R.setEXP(c.R.getEXP() + c.map.getMapExp());//���ͨ������
		cout << "ͨ��������" << c.map.getMapExp() << endl;//��ӡ����
		g_gongji = false;
		//��ӡ��ɫ��Ϣ
		c.R.show();

	}
}
