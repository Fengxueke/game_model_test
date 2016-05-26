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
		cout << "技能CD解除冷却！" << endl;
		d_skill::EndCD();// 技能解除冷却
		break;

	}
}
void d_skill::skill(Role r, Monster g, d_skill d_skill, character c)
{
	switch (c.R.getD_skill()) {
	case 1:
	{
		cout << "请输入要释放role1的技能：" << endl;
		cout << "1.榴弹星击--等级：2--攻击力：150--防御：施放期间无敌--冷却：3s" << endl;
		cout << "2.旋风腿--等级：4--攻击力：350--防御：0--冷却：4s" << endl;

		SetTimer(0,1, 10000, NULL);//final Timer timer1 = new Timer();// 计时器控制技能cd

		int s1 = 0;
		cin >> s1;
		if (s1 == 1) {
			if (!d_skill.isInCD()) {// 技能不在冷却中，则可以攻击！否则失败
									// 判断是否在角色攻击范围内
				if ((c.R.getLevel() >= 2
					&& c.R.getR_xue() > 0
					&& c.G.getG_xue() > 0
					&& c.G.getG_x() - c.R.getRo_x() < c.R
					.getR_distance() / 2 && c.R.getR_tili() > 10)) {
					cout << "榴弹星击!!!" << endl;
					c.G.setG_xue(c.G.getG_xue() - 150);
					c.R.setR_tili(c.R.getR_tili() - 10);
					StartCD();// 技能开始冷却
					/*
					TimerTask tt = new TimerTask(){
						public void run() {
						cout << "技能CD解除冷却！" << endl
						EndCD();// 技能解除冷却
					}
					};
					timer1.schedule(tt, 10000);// 冷却时间10000毫秒
					*/
					void OnTimer(UINT_PTR nIDEvent);

											   // 判断怪物还没死亡
					if (c.G.getG_xue() > 0) {
						cout << "怪物的血量剩余为" << c.G.getG_xue() << endl;
						cout << "主角的体力剩余为" << c.R.getR_tili() << endl;
						cout << "输入2>>靠近" << c.G.getName()
							<< ",输入3>>远离" << c.G.getName() << "，输入4>>攻击"
							+ c.G.getName() << ",5>>释放技能" << endl;
					}
					else {
						// 以下和攻击类雷同
						cout << c.G.getName() << "死亡" << endl;
						cout << "你攻击了" << c.G.getName() << "获得"
							+ c.G.getG_exp() << "经验" << endl;
						c.R.setEXP(c.R.getEXP() + c.G.getG_exp());
						l.level::Level(c, r);
						// 判断升级
						cout << "是否继续战斗？1/0?" << endl;
						int fight = 0;
						cin >> fight;
						if (fight == 1) {
							c.G.killcount++;// 击杀怪物数量
							c.R.show();
							c.randomMonster();
						}
						else {
							c.R.show();
							cout << "你共击败了"
								<< (c.G.killcount + 1) << "个怪物" << endl;
						}
					}

				}
				else {
					cout << "攻击失败！" << endl;// 不符合各种条件，则默认为攻击失败！还待完善
				}

			}

			else {
				cout << "技能CD冷却中，不能释放！" << endl;
			}

		}
	}
		break;

	case 2:
	{
		cout << "请输入要释放的role2技能：" << endl;
		cout << "1.榴弹星击--等级：2--攻击力：150--防御：施放期间无敌--冷却：3s" << endl;
		cout << "2.旋风腿--等级：4--攻击力：350--防御：0--冷却：4s" << endl;
		//final Timer timer2 = new Timer();
		SetTimer(0, 1, 10000, NULL);
		int s2 = 0;
		cin >> s2;
		if (s2 == 1) {
			if (!d_skill.isInCD()) {// 技能不在冷却中，则可以攻击！否则失败

				if ((c.R.getLevel() >= 2
					&& c.R.getR_xue() > 0
					&& c.G.getG_xue() > 0
					&& c.G.getG_x() - c.R.getRo_x() < c.R
					.getR_distance() / 2 && c.R.getR_tili() > 10)) {// 判断是否在角色攻击范围内
					cout << "榴弹星击!!!" << endl;
					c.G.setG_xue(c.G.getG_xue() - 150);
					c.R.setR_tili(c.R.getR_tili() - 10);
					StartCD();// 技能开始冷却
					/*
					TimerTask tt = new TimerTask(){
						public void run() {
						cout << "技能CD解除冷却！" << endl;
						EndCD();// 技能解除冷却
					}
					};
					timer2.schedule(tt, 10000);// 冷却时间
*/
					void OnTimer(UINT_PTR nIDEvent);
					if (c.G.getG_xue() > 0) {
						cout << "怪物的血量剩余为" << c.G.getG_xue() << endl;
						cout << "主角的体力剩余为" << c.R.getR_tili() << endl;
						cout << "输入2>>靠近" << c.G.getName()
							<< ",输入3>>远离" << c.G.getName() << "，输入4>>攻击"
							<< c.G.getName() << ",5>>释放技能" << endl;
					}
					else {

						cout << c.G.getName() << "死亡" << endl;
						cout << "你攻击了" << c.G.getName() << "获得"
							<< c.G.getG_exp() << "经验" << endl;
						c.R.setEXP(c.R.getEXP() + c.G.getG_exp());
						l.level::Level(c, r);
						// 判断升级

						cout << "是否继续战斗？1/0?" << endl;
						int fight = 0;
						cin >> fight;
						if (fight == 1) {
							c.G.killcount++;
							c.R.show();
							c.randomMonster();
						}
						else {
							c.R.show();
							cout << "你共击败了"
								+ (c.G.killcount + 1) << "个怪物" << endl;
						}
					}
				}
				else {
					cout << "攻击失败！" << endl;
				}

			}

			else {
				cout << "技能CD冷却中，不能释放！" << endl;
			}

		} 
	}
		break;
  
	case 3:
	{
		cout << "请输入要释放role3的技能：" << endl;
		cout << "1.榴弹星击--等级：2--攻击力：150--防御：施放期间无敌--冷却：3s" << endl;
		cout << "2.旋风腿--等级：4--攻击力：350--防御：0--冷却：4s" << endl;
		//final Timer timer3 = new Timer();
		SetTimer(0, 1, 10000, NULL);
		int s3 = 0;
		cin >> s3;
		if (s3 == 1) {
			if (!d_skill.isInCD()) {// 技能不在冷却中，则可以攻击！否则失败

				if ((c.R.getLevel() >= 2
					&& c.R.getR_xue() > 0
					&& c.G.getG_xue() > 0
					&& c.G.getG_x() - c.R.getRo_x() < c.R
					.getR_distance() / 2 && c.R.getR_tili() > 10)) {// 判断是否在角色攻击范围内
					cout << "榴弹星击!!!" << endl;
					c.G.setG_xue(c.G.getG_xue() - 150);
					c.R.setR_tili(c.R.getR_tili() - 10);
					StartCD();// 技能开始冷却
					/*
					TimerTask tt = new TimerTask(){
						public void run() {
						cout << "技能CD解除冷却！" << endl;
						EndCD();// 技能解除冷却
					}
					};
					timer3.schedule(tt, 10000);// 冷却时间
*/
					void OnTimer(UINT_PTR nIDEvent);
					if (c.G.getG_xue() > 0) {
						cout << "怪物的血量剩余为" << c.G.getG_xue() << endl;
						cout << "主角的体力剩余为" << c.R.getR_tili() << endl;
						cout << "输入2>>靠近" << c.G.getName()
							<< ",输入3>>远离" << c.G.getName() << "，输入4>>攻击"
							+ c.G.getName() << ",5>>释放技能" << endl;
					}
					else {

						cout << c.G.getName() << "死亡" << endl;
						cout << "你攻击了" << c.G.getName() << "获得"
							+ c.G.getG_exp() << "经验" << endl;
						c.R.setEXP(c.R.getEXP() + c.G.getG_exp());
						l.level::Level(c, r);
						// 判断升级

						cout << "是否继续战斗？1/0?" << endl;
						int fight = 0;
						cin >> fight;
						if (fight == 1) {
							c.G.killcount++;
							c.R.show();
							c.randomMonster();
						}
						else {
							c.R.show();
							cout << "你共击败了"
								+ (c.G.killcount + 1) << "个怪物" << endl;
						}
					}
				}
				else {
					cout << "攻击失败！" << endl;
				}

			}

			else {
				cout << "技能CD冷却中，不能释放！" << endl;
			}

		}
	}
		break;
	}

}
