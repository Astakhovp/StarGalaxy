#include <boost\uuid\uuid_io.hpp>
#include "GameConst.h"
#include "Util.h"
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
	tag = generate_guid();
	Coord.x = static_cast <double> (rand()) / (static_cast <double> (RAND_MAX / GalaxySize.x));
	Coord.y = static_cast <double> (rand()) / (static_cast <double> (RAND_MAX / GalaxySize.y));

	Size = rand() % StarMaxSize;
	Population = 0; Industry = 0;

}

using namespace tinyxml2;
XMLError TStar::WriteToXML(XMLDocument * xmlDoc, XMLNode * ParentNode)
{
	XMLElement * pElement = xmlDoc->NewElement("Star");
	ParentNode->InsertEndChild(pElement);

	XMLElement * sElement = xmlDoc->NewElement("GUID");
	sElement->SetText( boost::uuids::to_string(tag).c_str());
	pElement->InsertEndChild(sElement);

	sElement = xmlDoc->NewElement("X");
	sElement->SetText(Coord.x);
	pElement->InsertEndChild(sElement);

	sElement = xmlDoc->NewElement("Y");
	sElement->SetText(Coord.y);
	pElement->InsertEndChild(sElement);

	sElement = xmlDoc->NewElement("Size");
	sElement->SetText((int) Size);
	pElement->InsertEndChild(sElement);

	sElement = xmlDoc->NewElement("Name");
	sElement->SetText(Name.c_str());
	pElement->InsertEndChild(sElement);

	return XML_SUCCESS;
}

XMLError TStarList::WriteToXML(XMLDocument * xmlDoc, XMLNode * ParentNode)
{

	XMLElement * pElement = xmlDoc->NewElement("Stars");
	ParentNode->InsertEndChild(pElement);

	for (int i = 0; i < size(); i++)
	{
		TStar &Star = at(i);
		Star.WriteToXML(xmlDoc, pElement);
	}

	return XML_SUCCESS;
}
