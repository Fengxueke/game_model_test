#include "stdafx.h"
#include "d_skill.h"
#include <iostream>
#include <Windows.h>
using namespace std;
bool d_skill::inCD = false;
bool d_skill::isInCD()
{
	return inCD;
}

void d_skill::StartCD()
{
	inCD = true;
}

void d_skill::EndCD()
{
	inCD = false;
}
void OnTimer(UINT_PTR nIDEvent) {
	switch (nIDEvent) {
	case 1:
		cout << "����CD�����ȴ��" << endl;
		d_skill::EndCD();// ���ܽ����ȴ
		break;

	}
}
void d_skill::skill(Role r, Monster g, d_skill d_skill, character c)
{
	switch (c.R.getD_skill()) {
	case 1:
	{
		cout << "������Ҫ�ͷ�role1�ļ��ܣ�" << endl;
		cout << "1.���ǻ�--�ȼ���2--��������150--������ʩ���ڼ��޵�--��ȴ��3s" << endl;
		cout << "2.������--�ȼ���4--��������350--������0--��ȴ��4s" << endl;

		SetTimer(0,1, 10000, NULL);//final Timer timer1 = new Timer();// ��ʱ�����Ƽ���cd

		int s1 = 0;
		cin >> s1;
		if (s1 == 1) {
			if (!d_skill.isInCD()) {// ���ܲ�����ȴ�У�����Թ���������ʧ��
									// �ж��Ƿ��ڽ�ɫ������Χ��
				if ((c.R.getLevel() >= 2
					&& c.R.getR_xue() > 0
					&& c.G.getG_xue() > 0
					&& c.G.getG_x() - c.R.getRo_x() < c.R
					.getR_distance() / 2 && c.R.getR_tili() > 10)) {
					cout << "���ǻ�!!!" << endl;
					c.G.setG_xue(c.G.getG_xue() - 150);
					c.R.setR_tili(c.R.getR_tili() - 10);
					StartCD();// ���ܿ�ʼ��ȴ
					/*
					TimerTask tt = new TimerTask(){
						public void run() {
						cout << "����CD�����ȴ��" << endl
						EndCD();// ���ܽ����ȴ
					}
					};
					timer1.schedule(tt, 10000);// ��ȴʱ��10000����
					*/
					void OnTimer(UINT_PTR nIDEvent);

											   // �жϹ��ﻹû����
					if (c.G.getG_xue() > 0) {
						cout << "�����Ѫ��ʣ��Ϊ" << c.G.getG_xue() << endl;
						cout << "���ǵ�����ʣ��Ϊ" << c.R.getR_tili() << endl;
						cout << "����2>>����" << c.G.getName()
							<< ",����3>>Զ��" << c.G.getName() << "������4>>����"
							+ c.G.getName() << ",5>>�ͷż���" << endl;
					}
					else {
						// ���º͹�������ͬ
						cout << c.G.getName() << "����" << endl;
						cout << "�㹥����" << c.G.getName() << "���"
							+ c.G.getG_exp() << "����" << endl;
						c.R.setEXP(c.R.getEXP() + c.G.getG_exp());
						l.level::Level(c, r);
						// �ж�����
						cout << "�Ƿ����ս����1/0?" << endl;
						int fight = 0;
						cin >> fight;
						if (fight == 1) {
							c.G.killcount++;// ��ɱ��������
							c.R.show();
							c.randomMonster();
						}
						else {
							c.R.show();
							cout << "�㹲������"
								<< (c.G.killcount + 1) << "������" << endl;
						}
					}

				}
				else {
					cout << "����ʧ�ܣ�" << endl;// �����ϸ�����������Ĭ��Ϊ����ʧ�ܣ���������
				}

			}

			else {
				cout << "����CD��ȴ�У������ͷţ�" << endl;
			}

		}
	}
		break;

	case 2:
	{
		cout << "������Ҫ�ͷŵ�role2���ܣ�" << endl;
		cout << "1.���ǻ�--�ȼ���2--��������150--������ʩ���ڼ��޵�--��ȴ��3s" << endl;
		cout << "2.������--�ȼ���4--��������350--������0--��ȴ��4s" << endl;
		//final Timer timer2 = new Timer();
		SetTimer(0, 1, 10000, NULL);
		int s2 = 0;
		cin >> s2;
		if (s2 == 1) {
			if (!d_skill.isInCD()) {// ���ܲ�����ȴ�У�����Թ���������ʧ��

				if ((c.R.getLevel() >= 2
					&& c.R.getR_xue() > 0
					&& c.G.getG_xue() > 0
					&& c.G.getG_x() - c.R.getRo_x() < c.R
					.getR_distance() / 2 && c.R.getR_tili() > 10)) {// �ж��Ƿ��ڽ�ɫ������Χ��
					cout << "���ǻ�!!!" << endl;
					c.G.setG_xue(c.G.getG_xue() - 150);
					c.R.setR_tili(c.R.getR_tili() - 10);
					StartCD();// ���ܿ�ʼ��ȴ
					/*
					TimerTask tt = new TimerTask(){
						public void run() {
						cout << "����CD�����ȴ��" << endl;
						EndCD();// ���ܽ����ȴ
					}
					};
					timer2.schedule(tt, 10000);// ��ȴʱ��
*/
					void OnTimer(UINT_PTR nIDEvent);
					if (c.G.getG_xue() > 0) {
						cout << "�����Ѫ��ʣ��Ϊ" << c.G.getG_xue() << endl;
						cout << "���ǵ�����ʣ��Ϊ" << c.R.getR_tili() << endl;
						cout << "����2>>����" << c.G.getName()
							<< ",����3>>Զ��" << c.G.getName() << "������4>>����"
							<< c.G.getName() << ",5>>�ͷż���" << endl;
					}
					else {

						cout << c.G.getName() << "����" << endl;
						cout << "�㹥����" << c.G.getName() << "���"
							<< c.G.getG_exp() << "����" << endl;
						c.R.setEXP(c.R.getEXP() + c.G.getG_exp());
						l.level::Level(c, r);
						// �ж�����

						cout << "�Ƿ����ս����1/0?" << endl;
						int fight = 0;
						cin >> fight;
						if (fight == 1) {
							c.G.killcount++;
							c.R.show();
							c.randomMonster();
						}
						else {
							c.R.show();
							cout << "�㹲������"
								+ (c.G.killcount + 1) << "������" << endl;
						}
					}
				}
				else {
					cout << "����ʧ�ܣ�" << endl;
				}

			}

			else {
				cout << "����CD��ȴ�У������ͷţ�" << endl;
			}

		} 
	}
		break;
  
	case 3:
	{
		cout << "������Ҫ�ͷ�role3�ļ��ܣ�" << endl;
		cout << "1.���ǻ�--�ȼ���2--��������150--������ʩ���ڼ��޵�--��ȴ��3s" << endl;
		cout << "2.������--�ȼ���4--��������350--������0--��ȴ��4s" << endl;
		//final Timer timer3 = new Timer();
		SetTimer(0, 1, 10000, NULL);
		int s3 = 0;
		cin >> s3;
		if (s3 == 1) {
			if (!d_skill.isInCD()) {// ���ܲ�����ȴ�У�����Թ���������ʧ��

				if ((c.R.getLevel() >= 2
					&& c.R.getR_xue() > 0
					&& c.G.getG_xue() > 0
					&& c.G.getG_x() - c.R.getRo_x() < c.R
					.getR_distance() / 2 && c.R.getR_tili() > 10)) {// �ж��Ƿ��ڽ�ɫ������Χ��
					cout << "���ǻ�!!!" << endl;
					c.G.setG_xue(c.G.getG_xue() - 150);
					c.R.setR_tili(c.R.getR_tili() - 10);
					StartCD();// ���ܿ�ʼ��ȴ
					/*
					TimerTask tt = new TimerTask(){
						public void run() {
						cout << "����CD�����ȴ��" << endl;
						EndCD();// ���ܽ����ȴ
					}
					};
					timer3.schedule(tt, 10000);// ��ȴʱ��
*/
					void OnTimer(UINT_PTR nIDEvent);
					if (c.G.getG_xue() > 0) {
						cout << "�����Ѫ��ʣ��Ϊ" << c.G.getG_xue() << endl;
						cout << "���ǵ�����ʣ��Ϊ" << c.R.getR_tili() << endl;
						cout << "����2>>����" << c.G.getName()
							<< ",����3>>Զ��" << c.G.getName() << "������4>>����"
							+ c.G.getName() << ",5>>�ͷż���" << endl;
					}
					else {

						cout << c.G.getName() << "����" << endl;
						cout << "�㹥����" << c.G.getName() << "���"
							+ c.G.getG_exp() << "����" << endl;
						c.R.setEXP(c.R.getEXP() + c.G.getG_exp());
						l.level::Level(c, r);
						// �ж�����

						cout << "�Ƿ����ս����1/0?" << endl;
						int fight = 0;
						cin >> fight;
						if (fight == 1) {
							c.G.killcount++;
							c.R.show();
							c.randomMonster();
						}
						else {
							c.R.show();
							cout << "�㹲������"
								+ (c.G.killcount + 1) << "������" << endl;
						}
					}
				}
				else {
					cout << "����ʧ�ܣ�" << endl;
				}

			}

			else {
				cout << "����CD��ȴ�У������ͷţ�" << endl;
			}

		}
	}
		break;
	}

}
