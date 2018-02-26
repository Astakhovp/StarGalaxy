#pragma once
/*
 20180223
 ������ ����� ������ ��� ��������� ���������� ��������� ����, ����� ��� ������������ ������ �����, ���������� ����� � �.�.
*/

#include "GameTypes.h"
#include "LightClasses.h"

class GenerateParams : TXmlWritable
{
public:

	TCoord* MaxCoord;
	unsigned int Stars;
	tinyxml2::XMLError SaveToFile(void);

	GenerateParams(double, double);
	~GenerateParams();
};

