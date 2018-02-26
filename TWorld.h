#pragma once
#include "LightClasses.h"
#include "GenerateParams.h"


class TWorld
{
private:
	TStarList StarList;
	TCoord MaxCoord;
	ObjectsMaxQuantity TotalStars;
public:
	void Generate(GenerateParams);
	TWorld();
	~TWorld();

	tinyxml2::XMLError SaveToFile(char*);

};

