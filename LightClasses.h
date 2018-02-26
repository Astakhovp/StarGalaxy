#pragma once
/*
20180223
Данный файл создан для определения всяких простых классов.
*/

#include "GameTypes.h"
#include "tinyxml2.h"
#include <vector>

#define StarDensity 100

struct TCoord
{
public:
	double x, y;
	TCoord(double MaxX, double MaxY);
	TCoord();
};

class TXmlWritable
{
public:
	
	//virtual tinyxml2::XMLError SaveToFile(void)=0;
};

struct TStar
{
public:
	TCoord Coord;
	StarSize Size, Population, Industry;
};

class TStarList : public std::vector < TStar >, TXmlWritable
{


};
