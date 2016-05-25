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

//static DWORD WINAPI Fun(LPVOID lpParameter);
//cout << "here" << endl;
Role r("", 0, 0, 0, 0, 0, 0, 0, 0);
//cout << "here" << endl;
Monster g("", 0, "", 0, 0, 0, 0, 0, 0, 0);
//static Main m;
Map map(0, 0, 0);
static character c;
attackGuai atk(r, c, 0, 0);
static d_skill dskill;
random ran(r, g, c);
Remove rm(r, g, c, g_gongji, r_gongji, canLook, biao1, biao2);
static level l;

DWORD WINAPI Thread1(LPVOID lpParamter)
{
	THreadTest* mythread = (THreadTest*)lpParamter;
	mythread->s.start();
	//start();
	return 0;
}

int main()
{
	cout << "输入1开始游戏" << endl;
	int start;
	cin >> start;
	if (start == 1) {
		/*
		Thread thread = new Thread(){
			public void run() {
			s.start();
		}
		};
		thread.start();*/
		//s.start();
		
		cout << "线程启动" << endl;
		cout << "游戏开始" << endl;
		c.init();//对应属性类
		c.randomMonster();
		c.mapset();
		

		cout << "输入2>>靠近" << c.G.getName() << ",输入3>>远离"
			<< c.G.getName() << "，输入4>>攻击" << c.G.getName() << ",5>>释放技能" << endl;

		comeToGuai ctg(r, g, c); //值的问题，放这里
	


	while (c.R.getR_xue() > 0 && c.G.getG_xue() > 0) {
		int come = 0;
		cin >> come;
		if (come == 2) {			
			//cout << c.map.getX() << endl;
			//cout << c.R.getRo_x() << endl;
			startgame s(r, g, c, g_gongji, r_gongji, canLook, biao1, biao2);
			THreadTest *tt = new THreadTest();
			tt->s = s;
			HANDLE hThread = CreateThread(NULL, 0, Thread1, tt, 0, NULL);
			ran.randomxue();
			ctg.ComeToGuai();
			

		}
		if (come == 3) {
			ran.randomxue();
			rm.Remove_1();

		}
		if (come == 4) {
			atk.AttackGuai();
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
