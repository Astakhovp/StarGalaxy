#pragma once
/*
 20180223
 ������ ����� ������ ��� ��������� ���������� ��������� ����, ����� ��� ������������ ������ �����, ���������� ����� � �.�.
*/

#include "GameTypes.h"
#include "LightClasses.h"

class GenerateParams 
{
public:
	char* filename;
	TCoord MaxCoord;
	ObjectsMaxQuantity TotalStars;

	tinyxml2::XMLError SaveToFile(void);

	GenerateParams(double, double);
	~GenerateParams();
};

