#include "stdafx.h"
#include "comeToGuai.h"
#include <iostream>
using namespace std;
comeToGuai::comeToGuai(Role &R, Monster &G, character &C)
{
	//�̳� super();
	r = R;
	g = G;
	c = C;
}
character comeToGuai::ComeToGuai(character c)
{
	//�жϵ�ǰλ���Ƿ��ڵ�ͼ����
		//cout << c.R.getRo_x() << endl;
		//cout << c.map.getX() << endl;
		if(c.R.getRo_x()<c.map.getX()){
		cout << "���ڿ���" << c.G.getName() << endl;
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
		cout << c.R.getName() << "��λ��x��" << c.R.getRo_x() << " y:"
				<< c.R.getRo_y() << endl;
		cout << c.G.getName() << "��λ��x��" << c.G.getG_x() << " y:"
				<< c.G.getG_y() << endl;
		return c;
		}else{
			//������ͨ��
			cout << "��ϲͨ�أ�" << endl;
			c.R.setEXP(c.R.getEXP()+c.map.getMapExp());//��ȡͨ�ؾ���
			cout << "ͨ��������" << c.map.getMapExp() << endl;			
			c.R.show();			
		}
}
