#include "stdafx.h"
#include <iostream>
#include "attackGuai.h"
using namespace std;
attackGuai::attackGuai()
{
}
attackGuai::attackGuai(Role &R, character &C, bool G_gongji, bool R_gongji)
{
	
	r = R;
	c = C;
	g_gongji = G_gongji;
	r_gongji = R_gongji;
}

character attackGuai::AttackGuai(character &c)
{
	// �ж��Ƿ��ڽ�ɫ������Χ��
	if ((c.G.getG_x() - c.R.getRo_x() > c.R.getR_distance() / 2)) {
		r_gongji = false;
		cout << "���ڹ�����Χ��" << endl;
	}
	if ((c.G.getG_x() - c.R.getRo_x() <= c.R.getR_distance() / 2)) {
		r_gongji = true;
		c.G.setG_xue(c.G.getG_xue() - c.R.getR_baseskill());
		r.setR_tili(c.R.getR_tili() - 5);//ÿ���չ���������-5
		cout << "����������" << endl;
	}

	cout << c.G.getName() << "��Ѫ��ʣ��Ϊ:" << c.G.getG_xue() << endl;
	cout << c.R.getName() << "������ʣ��Ϊ:" << c.R.getR_tili() << endl;
	//�жϹ����Ƿ�����
	if (c.G.getG_xue() <= 0 && c.R.getR_xue() > 0) {
		g_gongji = false;
		cout << c.G.getName() << "����" << endl;
		cout << "�㹥����" << c.G.getName() << "���" << c.G.getG_exp()
			<< "����" << endl;
		c.R.setEXP(c.R.getEXP() + c.G.getG_exp());// ��ɱ�����þ���
		l.level::Level(c,r);
		// �ж�����
		c.G.killcount++;// ��ɱ�����ۼ�
		cout << "�Ƿ����ս����1/0?" << endl;
		int fight = 0;
		cin >> fight;
		switch (fight) {
		case 1:
			c.R.show();//��ӡ��ɫ��Ϣ
			c.randomMonster();//����������ɹ���
			break;
		case 0:
			c.R.show();//��ӡ��ɫ��Ϣ
			cout << "�㹲������" << c.G.killcount << "������" << endl;
			break;
		}
	}
	return c;
}
