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
			}
			if (c.R.getRo_x() - c.G.getG_x() > c.R.getR_distance()) {
				cout << "���ӳ�" << c.G.getName() << "�Ĺ�����Χ����"
					<< c.G.getName() << "���ڿ���....." << endl;
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
				cout << "���ӳ�" << c.G.getName() << "�Ŀ��ӷ�Χ" << endl;
				biao1 = 0;
				return c;
			}
			if (c.G.getG_x() - c.R.getRo_x() > c.R.getR_distance()) {
				cout << "���ӳ�" << c.G.getName() << "�Ĺ�����Χ����"
					<< c.G.getName() << "���ڿ���....." << endl;
				biao2 = 0;
			}

			return c;
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
