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
XMLError TStarList::WriteToXML(XMLDocument * xmlDoc, XMLNode * CurrNode)
{
	for (int i = 0; i < size(); i++)
	{
		TStar &Star = at(i);
		//Star = at(i);
		XMLElement * pElement = xmlDoc->NewElement("Star");
		pElement->SetText(Star.Coord.x);
		CurrNode->InsertEndChild(pElement);
	}
	
	//// Проход по вектору с выводом значений
	//for (int n : TSta) {
	//	std::cout << n << '\n';
	//}





	//pRoot->InsertEndChild(pElement);

	//XMLElement * pElement;




	return XML_SUCCESS;
}
