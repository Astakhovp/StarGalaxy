#pragma once
/*
 20180223
 ������ ����� ������ ��� ��������� ���������� ��������� ����, ����� ��� ������������ ������ �����, ���������� ����� � �.�.
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

