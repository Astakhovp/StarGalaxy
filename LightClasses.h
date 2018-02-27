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

using namespace tinyxml2;
class TStar : public TXmlWritable
{
public:
	TCoord Coord;
	StarSize Size, Population, Industry;
	TStar(TCoord GalaxySize);
	XMLError WriteToXML(XMLDocument *, XMLNode * ParentNode);
};

class TStarList : public std::vector < TStar >, TXmlWritable
{
public:
	XMLError WriteToXML(XMLDocument *, XMLNode * ParentNode);
};
