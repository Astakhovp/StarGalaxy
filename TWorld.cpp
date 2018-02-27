#include "TWorld.h"
#include <stdlib.h>



void TWorld::Generate(GenerateParams Params)
{
	MaxCoord = Params.MaxCoord;
	TotalStars = Params.TotalStars;
	StarList.reserve(Params.TotalStars);

	for (ObjectsMaxQuantity i = 0; i < Params.TotalStars; i++)
	{
		TStar Star(Params.MaxCoord);
		StarList.insert(StarList.end(), Star);
	}

}

TWorld::TWorld()
{
}


TWorld::~TWorld()
{
	StarList.clear();
}

using namespace tinyxml2;
XMLError TWorld::SaveToFile(char * filename)
{
	XMLDocument xmlDoc;
	xmlDoc.NewDeclaration();

	XMLNode * pRoot = xmlDoc.NewElement("GalaxyState");
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

	StarList.WriteToXML(&xmlDoc, pRoot);



	XMLError eResult = xmlDoc.SaveFile(filename);
	return eResult;
}

