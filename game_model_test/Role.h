#pragma once
#include <string>
using namespace std;
class Role {
private:
	string name;
	int ro_x = 0;//��������
	int ro_y = 0;//��������
	int fangxiang;//����δ���ã�
	int r_xue;//��ɫѪ��
	int r_distance;//��ɫ��������
	int r_baseskill;//��ɫ��������
	int r_defence;//��ɫ����ֵ
	int r_tili;//��ɫ����
	int level = 1;//��ɫ��ʼ�ȼ�
	int EXP;//��ɫ����
	int d_skill;//��ɫ�Կ��Ƽ���
public:	
	Role(string name, int r_xue, int r_tili, int r_defence,
		int r_baseskill, int r_distance, int EXP, int d_skill, int level);
	Role();
	int getLevel();
	void setLevel(int level);
	int getR_xue();
	void setR_xue(int r_xue);
	int getRo_y();
	void setRo_y(int ro_y);
	int getRo_x();
	void setRo_x(int ro_x);
	int getFangxiang();
	void setFangxiang(int fangxiang);
	int getR_baseskill();
	void setR_baseskill(int r_baseskill);
	int getR_defence();
	void setR_defence(int r_defence);
	int getR_tili();
	void setR_tili(int r_tili);
	int getR_distance();
	void setR_distance(int r_distance);
	int getEXP();
	void setEXP(int eXP);
	string getName();
	void setName(string name);
	int getD_skill();
	void setD_skill(int d_skill);
	void show();
	~Role();
};