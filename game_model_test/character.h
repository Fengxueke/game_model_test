#pragma once
#include "Map.h"
#include "Monster.h"
#include "Role.h"
class character {
     public:		 
		 const static int L_rect_x = 300; //java������ final static
		 const static int L_rect_y = 300;
		 Map map;
		 Role R;
		 Monster G;
		 //Main m;
		 character();
		 void init();//��ʼ������
		 void randomMonster();
		 void mapset();
};