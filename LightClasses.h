#pragma once
/*
20180223
Данный файл создан для определения всяких простых классов.
*/

#include "tinyxml2.h"

#define StarDensity 100

class TCoord
{
public:
	double x, y;
	TCoord(double MaxX, double MaxY);
	TCoord();
};

class TXmlWritable
{
public:
	char* filename;
	
	virtual tinyxml2::XMLError SaveToFile(void)=0;
};
