#include "character.h"
#include "stdafx.h"
#include <iostream>
#define Random(x) (rand() % x)
using namespace std;

character::character()
{
}

void character::init()
{
	int input = 0;
	cout << "ѡ�����ǣ�" << endl;;
	cout << "1.���������ʿ���D�D��" << endl;;
	cout << "2.��еŮ���ߨD�Dӣ" << endl;;
	cout << "3.��ƽ����������-��³" << endl;;
	cin >> input;
	switch (input) {
	case 1:
		R.setName("���������ʿ���D�D��");
		R.setR_xue(500);
		R.setR_tili(100);
		R.setR_defence(50);
		R.setR_baseskill(100);
		R.setR_distance(40);
		R.setEXP(0);
		R.setD_skill(1);

		break;
	case 2:
		R.setName("��еŮ���ߨD�Dӣ");
		R.setR_xue(300);
		R.setR_tili(100);
		R.setR_defence(40);
		R.setR_baseskill(120);
		R.setR_distance(40);
		R.setEXP(0);
		R.setD_skill(2);
		break;
	case 3:
		R.setName("��ƽ����������-��³");
		R.setR_xue(500);
		R.setR_tili(100);
		R.setR_defence(80);
		R.setR_baseskill(80);
		R.setR_distance(40);
		R.setEXP(0);
		R.setD_skill(3);
		break;

	}
	R.show();

}

void character::randomMonster()
{
	int rd = Random(3) + 1;
	switch (rd) {
	case 1:
		G.setName("٤��С�๤");
		G.setG_xue(200);
		G.setSname("�޻�");
		G.setG_skill(50);
		G.setG_defence(0);
		G.setG_exp(10);
		G.setTime(1500);
		G.setDistance(5);
		G.setG_x(400);
		G.setG_y(400);
		break;
	case 2:
		G.setName("٤�������");
		G.setG_xue(400);
		G.setSname("���");
		G.setG_skill(75);
		G.setG_defence(0);
		G.setG_exp(15);
		G.setTime(1500);
		G.setDistance(10);
		G.setG_x(400);
		G.setG_y(400);
		break;
	case 3:
		G.setName("٤��������");
		G.setG_xue(600);
		G.setSname("�ǹ���");
		G.setG_skill(100);
		G.setG_defence(0);
		G.setG_exp(20);
		G.setTime(2000);
		G.setDistance(15);
		G.setG_x(400);
		G.setG_y(400);
		break;
	}
	G.show();
}

void character::mapset()
{
	int m = 1;
	switch (m) {
	case 1:
		map.setX(800);
		map.setY(400);
		map.show();
		break;
	}
}
