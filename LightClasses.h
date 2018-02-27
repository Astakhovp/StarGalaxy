#pragma once
/*
20180223
������ ���� ������ ��� ����������� ������ ������� �������.
*/

#include <vector>
#include <string>
#include "Util.h"
#include "GameTypes.h"
#include "tinyxml2.h"

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
	boost::uuids::uuid tag;
	TCoord Coord;
	std::string Name;
	StarSize Size, Population, Industry;
	TStar(TCoord GalaxySize);
	XMLError WriteToXML(XMLDocument *, XMLNode * ParentNode);
};

class TStarList : public std::vector < TStar >, TXmlWritable
{
public:
	XMLError WriteToXML(XMLDocument *, XMLNode * ParentNode);
};
