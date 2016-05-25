#pragma once
#include "character.h"
class Map{
private:	
	int X;
	int Y;
	int MapExp;
public:
	Map();
	Map(int x, int y, int mapExp);
	void mapExp();
	int getX();
	void setX(int x);
	int getY();
	void setY(int y);
	int getMapExp();
	void setMapExp(int mapExp);
	void show();
};