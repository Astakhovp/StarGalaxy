#include <iostream>
#include <vector>
#include <stdlib.h>

#include "TWorld.h"

#include "GameTypes.h"
#include "LightClasses.h"
#include "WorldGeneration.h"
#include "GenerateParams.h"

#ifdef _DEBUG
#include <crtdbg.h>
#define _CRTDBG_MAP_ALLOC
#endif


using namespace std;

template <typename T> 
class AVector : public vector <T>
{
};

int main()
{

	GenerateParams* Params = new GenerateParams(40, 40);
	Params->SaveToFile();

	TWorld World;
	World.Generate(*Params);
	World.SaveToFile("SaveWorld.xml");

	delete Params;

	World.~TWorld();

	//for (int i = 0; i < 3; i++)
	//{
	//	GenerateParams* Params = new GenerateParams(100.0, 200.0);
	//}



	//TCoord* Coord = new TCoord(1.0, 2.0);


	//AVector<int> Vec;
	
	//Vec.resize(20);

	//for (int i = 0; i < 20; i++)
	//{
	//	Vec[i] = rand();

	//}

	//for (int i = 0; i < 20; i++)
	//{
	//	cout << "i=" << i + 1 << "; elem = " << vec[i] << ";" << "\n";
	//}

	cout << "Hello, world!\n";


	//for (int i = 0; i < 1000; i++)
	//{
	//	AVector<int>* V2 = new AVector<int>;
	//	V2->resize(10);
	//	delete V2;
	//}

#ifdef _DEBUG
	_CrtDumpMemoryLeaks();
#endif
	//system("pause");

	return 0;

}

