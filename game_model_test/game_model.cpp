// game_model.cpp : �������̨Ӧ�ó������ڵ㡣
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
static Role r("", 0, 0, 0, 0, 0, 0, 0, 0);
//cout << "here" << endl;
static Monster g("", 0, "", 0, 0, 0, 0, 0, 0, 0);
//static Main m;
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
	cout << "����1��ʼ��Ϸ" << endl;
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
		
		cout << "�߳�����" << endl;
		

		cout << "��Ϸ��ʼ" << endl;
		c.init();//��Ӧ������
		c.randomMonster();
		c.mapset();
		

		cout << "����2>>����" << c.G.getName() << ",����3>>Զ��"
			<< c.G.getName() << "������4>>����" << c.G.getName() << ",5>>�ͷż���" << endl;

		static comeToGuai ctg(r, g, c);//ֵ�����⣬������
		startgame s(r, g, c, g_gongji, r_gongji, canLook, biao1, biao2);
		THreadTest *tt = new THreadTest();
		tt->s = s;
		
	
			HANDLE hThread = CreateThread(NULL, 0, Thread1, tt, 0, NULL);
		

	while (c.R.getR_xue() > 0 && c.G.getG_xue() > 0) {
		int come = 0;
		cin >> come;
		if (come == 2) {	
			//cout << c.map.getX() << endl;
			//cout << c.R.getRo_x() << endl;			
			ran.randomxue();
			c=ctg.ComeToGuai(c);
			//cout << "��ɫλ��-->" << c.R.getRo_x() << "  �ֵ�λ��" << c.G.getG_x() << endl;
			

		}
		if (come == 3) {
			//cout << "��ɫλ��-->" << c.R.getRo_x() << "  �ֵ�λ��" << c.G.getG_x() << endl;
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
