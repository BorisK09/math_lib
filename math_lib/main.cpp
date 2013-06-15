#include <iostream>
#include "math.h"


using namespace std;


int main()
{
	cout << "Start..." << endl;

	Vector2 vecA(0.5, 1.5);
	Vector2 vecB(2.5, 1.5);
	Vector2 vecC;

	cout << "(" << vecA.x << "; " << vecA.y << ")" << endl;
	cout << "(" << vecB.x << "; " << vecB.y << ")" << endl;
	cout << "(" << vecC.x << "; " << vecC.y << ")" << endl;

	cout << vecA.nColumns << "x" << vecA.nRows << endl;


	return 0;
}
