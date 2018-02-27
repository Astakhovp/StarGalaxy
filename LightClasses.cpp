#include "LightClasses.h"

TCoord::TCoord(double MaxX, double MaxY)
{
	x = MaxX;
	y = MaxY;
}

TCoord::TCoord()
{
}

TStar::TStar(TCoord GalaxySize)
{
	Coord.x = static_cast <double> (rand()) / (static_cast <double> (RAND_MAX / GalaxySize.x));
	Coord.y = static_cast <double> (rand()) / (static_cast <double> (RAND_MAX / GalaxySize.y));
}

using namespace tinyxml2;
XMLError TStar::WriteToXML(XMLDocument *, XMLNode * ParentNode)
{
	return XMLError();
}

XMLError TStarList::WriteToXML(XMLDocument * xmlDoc, XMLNode * ParentNode)
{

	XMLElement * pElement = xmlDoc->NewElement("Stars");
	ParentNode->InsertEndChild(pElement);

	for (int i = 0; i < size(); i++)
	{
		TStar &Star = at(i);
		XMLElement * sElement = xmlDoc->NewElement("Star");
		sElement->SetText(100);
		pElement->InsertEndChild(sElement);
	}

	return XML_SUCCESS;
}
