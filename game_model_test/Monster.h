#pragma once
#include <string>
using namespace std;
class Monster {
private:
	int g_x;//��������
	int g_y;//��������
	int fangxiang;//����δ���ã�
	int g_xue;//����Ѫ��
	int g_defence;//�������ֵ
	int g_skill;//���＼��
	int g_exp;//��ɱ����ɻ�ȡ����ֵ
	int time;//������ȴʱ��
	string name;//��������
	string sname;//���＼������
public:
	int distance;//��������
	int killcount;//��ɱ������
	const static int L_rect_x = 300;//���ù����ʼλ�� final =300
	const static int L_rect_y = 300;//���ù����ʼλ�� final =300
	Monster();
	Monster(string name, int G_xue, string sname, int G_skill,
		int g_defence, int time, int distance, int killcount, int g_x, int g_y);
	int getG_x();
	void setG_x(int g_x);
	int getG_y();
	void setG_y(int g_y);
	int getG_xue();
	void setG_xue(int g_xue);
	int getG_skill();
	void setG_skill(int g_skill);
	int getG_defence();
	void setG_defence(int g_defence);
	int getG_exp();
	void setG_exp(int g_exp);
	string getName();
	void setName(string name);
	int getTime();
	void setTime(int time);
	string getSname();
	void setSname(string sname);
	int getDistance();
	void setDistance(int distance);
	int getKillcount();
	void setKillcount(int killcount);
	void show();
};