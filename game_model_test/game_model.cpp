// game_model.cpp : 定义控制台应用程序的入口点。
//
#include "stdafx.h"
#include <iostream>
#include <Windows.h>
#include <thread>
using namespace std;

static DWORD WINAPI Thread1(LPVOID lpParameter);

struct THreadTest { 
	THreadTest();
	startgame s; };

const static bool g_gongji = false;
const static bool r_gongji = false;
const static bool canLook = false;
const static int biao1 = 0;
const static int biao2 = 0;


static Role r("", 0, 0, 0, 0, 0, 0, 0, 0);
static Monster g("", 0, "", 0, 0, 0, 0, 0, 0, 0);
static Map map(0, 0, 0);
static character c;
static attackGuai atk(r, c, 0, 0);
static d_skill dskill;
static random ran(r, g, c);
static Remove rm(r, g, c, g_gongji, r_gongji, canLook, biao1, biao2);
static level l;


DWORD WINAPI Thread1(LPVOID lpParamter)
{
	THreadTest* mythread = (THreadTest*)lpParamter;
	mythread->s.start(c);
	//start();
	return 0;
}

int main()
{
	cout << "输入1开始游戏" << endl;
	int start;
	cin >> start;
	if (start == 1) {
		
		cout << "线程启动" << endl;		
		cout << "游戏开始" << endl;
		c.init();//对应属性类
		c.randomMonster();
		c.mapset();		
		cout << "输入2>>靠近" << c.G.getName() << ",输入3>>远离"
			<< c.G.getName() << "，输入4>>攻击" << c.G.getName() << ",5>>释放技能" << endl;

		static comeToGuai ctg(r, g, c);//值的问题，放这里
		startgame s(r, g, c, g_gongji, r_gongji, canLook, biao1, biao2);
		THreadTest *tt = new THreadTest();
		tt->s = s;
		HANDLE hThread = CreateThread(NULL, 0, Thread1, tt, 0, NULL);
		

	while (c.R.getR_xue() > 0 && c.G.getG_xue() > 0) {
		int come = 0;
		cin >> come;
		if (come == 2) {	
			ran.randomxue();
			c=ctg.ComeToGuai(c);
		}
		if (come == 3) {
			ran.randomxue();
			rm.Remove_1(c);
		}
		if (come == 4) {
			atk.AttackGuai(c);
		}
		if (come == 5) {
			dskill.skill(r, g, dskill, c);
		}
	}
	}

    return 0;



}

THreadTest::THreadTest()
{
}
