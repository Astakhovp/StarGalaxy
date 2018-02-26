#include "GenerateParams.h"
#include "LightClasses.h"


using namespace tinyxml2;
XMLError GenerateParams::SaveToFile(void)
{
	XMLDocument xmlDoc;
	XMLNode * pRoot = xmlDoc.NewElement("Root");
	xmlDoc.InsertFirstChild(pRoot);

	XMLElement * pElement = xmlDoc.NewElement("IntValue");

	pElement->SetText(10);
	pRoot->InsertEndChild(pElement);

	pElement = xmlDoc.NewElement("Date");
	pElement->SetAttribute("day", 26);
	pElement->SetAttribute("month", "April");
	pElement->SetAttribute("year", 2014);
	pElement->SetAttribute("dateFormat", "26/04/2014");

	pRoot->InsertEndChild(pElement);
	XMLError eResult = xmlDoc.SaveFile(filename);
	return eResult;
}

GenerateParams::GenerateParams(double MaxX, double MaxY)
{

	TCoord* MaxCoord = new TCoord(MaxX, MaxY);
	ObjectsMaxQuantity Stars = (ObjectsMaxQuantity)(MaxX * MaxY / StarDensity);
	filename = "d:\\XML\\Params.xml";
}


GenerateParams::~GenerateParams()
{
	delete MaxCoord;
}
