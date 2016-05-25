#include "Map.h"
#include "stdafx.h"
#include <iostream>
using namespace std;
character c;
Map::Map()
{
}
Map::Map(int x, int y, int mapExp)
{
	Map:: X = x;
	Map:: Y = y;
	Map:: MapExp = mapExp;
}

void Map::mapExp()
{
	setMapExp((getMapExp() + c.R.getEXP())*c.R.getLevel());
}

int Map::getX()
{
	return X;
}

void Map::setX(int x)
{
	Map:: X = x;
}

int Map::getY()
{
	return Y;
}

void Map::setY(int y)
{
	Map:: Y = y;
}

int Map::getMapExp()
{
	return MapExp;
}

void Map::setMapExp(int mapExp)
{
	Map:: MapExp = mapExp;
}

void Map::show()
{
	cout << "地图长度为：" << getX() << "地图高度为：" << getY() << endl;
}
