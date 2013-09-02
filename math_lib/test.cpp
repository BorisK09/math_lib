#include <iostream>
#include "math.h"
#include "windows.h"


using namespace std;


int main()
{
	Vector2f vecB(1.1, 2.2), vecD(3.9, 2.8);

	Vector3f vecA(11.1, 22.2, 33.3), vecC;

	vecB = Vector2f(45, 98);

	VectorNf<2> vecF;

	vecF.v[0] = 0.5;
	vecF.v[1] = 1.6;

	vecB = -vecF;

	vecA = Vector3f(vecF, vecA.z);

	cout << vecA.x << ", " << vecA.y << ", " << vecA.z << endl;

	cout << 
	vecF.v[0] << 
	", " <<
	vecF.v[1] << 
	endl;

	cout << "--- Matrices ---" << endl;

	Matrix2x2f matA(1.1, 2.2,
		            3.3, 4.4);

	matA = matA * matA;

	cout << matA.m[0][0] << " " << matA.m[0][1] << endl;
	cout << matA.m[1][0] << " " << matA.m[1][1] << endl;

	Matrix2x2f matB;
	matB = transpose(matA);

	cout << endl;

	cout << matA.m[0][0] << " " << matA.m[0][1] << endl;
	cout << matA.m[1][0] << " " << matA.m[1][1] << endl;

	cout << vecB.x << ", " << vecB.y << endl;

	return 0;
}

