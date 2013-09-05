#include <iostream>

#include "h2_math.h"


using namespace std;

using namespace h2;


int main()
{
	Vector2f vecB(1.1f, 2.2f), vecD(3.9f, 2.8f);

	Vector3f vecA(11.1f, 22.2f, 33.3f), vecC;

	vecB = Vector2f(45.0f, 98.0f);

	VectorNf<3> vecF;

	vecF.v[0] = 0.5f;
	vecF.v[1] = 1.6f;

	vecB = -vecF;

	vecA = Vector3f(vecF, vecA.z);

	cout << vecA.x << ", " << vecA.y << ", " << vecA.z << endl;

	cout << 
	vecF.v[0] << 
	", " <<
	vecF.v[1] << 
	endl;

	cout << "--- Matrices ---" << endl;

	Matrix2x2f matA(1.1f, 2.2f,
		            3.3f, 4.4f);

	matA.setRow(0, 365.0f, 256.0f);
	matA.setRow(1, vecF);

	cout << matA.m[0][0] << " " << matA.m[0][1] << endl;
	cout << matA.m[1][0] << " " << matA.m[1][1] << endl;


	Matrix3x3f matB;

	matB.setIdentity();

	matB.transpose();

	matB = matA;

	cout << matB.m[0][0] << " " << matB.m[0][1] << " " << matB.m[0][2] << endl;
	cout << matB.m[1][0] << " " << matB.m[1][1] << " " << matB.m[1][2] << endl;
	cout << matB.m[2][0] << " " << matB.m[2][1] << " " << matB.m[2][2] << endl;

	Matrix4x4f matC;

	return 0;
}

