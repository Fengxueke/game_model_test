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
	cout << "选择主角：" << endl;;
	cout << "1.基因改造人士兵――龙" << endl;;
	cout << "2.机械女忍者――樱" << endl;;
	cout << "3.和平主义外星人-阿鲁" << endl;;
	cin >> input;
	switch (input) {
	case 1:
		R.setName("基因改造人士兵――龙");
		R.setR_xue(500);
		R.setR_tili(100);
		R.setR_defence(50);
		R.setR_baseskill(100);
		R.setR_distance(40);
		R.setEXP(0);
		R.setD_skill(1);

		break;
	case 2:
		R.setName("机械女忍者――樱");
		R.setR_xue(300);
		R.setR_tili(100);
		R.setR_defence(40);
		R.setR_baseskill(120);
		R.setR_distance(40);
		R.setEXP(0);
		R.setD_skill(2);
		break;
	case 3:
		R.setName("和平主义外星人-阿鲁");
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
		G.setName("伽马小监工");
		G.setG_xue(200);
		G.setSname("鞭击");
		G.setG_skill(50);
		G.setG_defence(0);
		G.setG_exp(10);
		G.setTime(1500);
		G.setDistance(5);
		G.setG_x(400);
		G.setG_y(400);
		break;
	case 2:
		G.setName("伽马防暴兵");
		G.setG_xue(400);
		G.setSname("射击");
		G.setG_skill(75);
		G.setG_defence(0);
		G.setG_exp(15);
		G.setTime(1500);
		G.setDistance(10);
		G.setG_x(400);
		G.setG_y(400);
		break;
	case 3:
		G.setName("伽马异能者");
		G.setG_xue(600);
		G.setSname("星光术");
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
