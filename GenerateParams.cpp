#include "GenerateParams.h"
#include "LightClasses.h"


using namespace tinyxml2;
XMLError GenerateParams::SaveToFile(void)
{
	XMLDocument xmlDoc;
	xmlDoc.NewDeclaration();

	XMLNode * pRoot = xmlDoc.NewElement("MapGenerationParams");
	xmlDoc.InsertFirstChild(pRoot);

	XMLElement * pElement = xmlDoc.NewElement("MapSize");
	pRoot->InsertEndChild(pElement);

	XMLElement * sElement = xmlDoc.NewElement("MaxX");
	sElement->SetText(MaxCoord.x);
	pElement->InsertEndChild(sElement);

	sElement = xmlDoc.NewElement("MaxY");
	sElement->SetText(MaxCoord.y);
	pElement->InsertEndChild(sElement);

	pElement = xmlDoc.NewElement("TotalStars");
	pElement->SetText(TotalStars);
	pRoot->InsertEndChild(pElement);


	XMLError eResult = xmlDoc.SaveFile(filename);
	return eResult;
}

GenerateParams::GenerateParams(double MaxX, double MaxY)
{

	MaxCoord.x = MaxX;
	MaxCoord.y = MaxY;
	TotalStars = (ObjectsMaxQuantity)(MaxX * MaxY / StarDensity);

	filename = "Params.xml";
}


GenerateParams::~GenerateParams()
{
}
