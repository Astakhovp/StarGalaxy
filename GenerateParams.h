#pragma once
/*
 20180223
 Данный класс создан для установки параметров генерации мира, такие как максимальный размер карты, количество звезд и т.д.
*/

#include "GameTypes.h"
#include "LightClasses.h"

class GenerateParams 
{
private:
	TCoord MaxCoord;
	ObjectsMaxQuantity TotalStars;
	

public:
	char* filename;

	tinyxml2::XMLError SaveToFile(void);

	GenerateParams(double, double);
	~GenerateParams();
};

