#include "stdafx.h"
#include <iostream>
#include "attackGuai.h"
using namespace std;
attackGuai::attackGuai()
{
}
attackGuai::attackGuai(Role r, character c, bool g_gongji, bool r_gongji)
{
	
	attackGuai::r = r;
	attackGuai::c = c;
	attackGuai::g_gongji = g_gongji;
	attackGuai::r_gongji = r_gongji;
}

void attackGuai::AttackGuai()
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

	cout << c.G.getName() << "��Ѫ��ʣ��Ϊ" << endl;
	cout << c.R.getName() << "������ʣ��Ϊ" << endl;
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
}
