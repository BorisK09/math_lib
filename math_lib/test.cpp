#include <iostream>
#include "math.h"
#include "windows.h"


using namespace std;


int main()
{

	Vector2f vecB(1.1, 2.2), vecD(3.9, 2.8);

	Vector3f vecA(11.1, 22.2, 33.3), vecC;

	vecB = Vector2f(45, 98);

	VectorNf<10> vecF;

	vecF.v[0] = 0.5;
	vecF.v[1] = 1.6;

	vecF = -vecF;

	vecB = vecF;

	vecA = Vector3f(vecF, vecA.z);

	cout << vecA.x << ", " << vecA.y << ", " << vecA.z << endl;

	cout << 
	vecF.v[0] << 
	", " <<
	vecF.v[1] << 
	endl;

	return 0;
}

