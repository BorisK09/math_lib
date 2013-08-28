/*
#include <cmath>


enum MATRIX_PACK
{
	ROW_MAJOR		= 0,
	COLUMN_MAJOR	= 1,
};
*/

/*
template <class BaseType, unsigned int _nRows, unsigned int _nColumns> 
class Matrix
{
public:

	const unsigned int nRows, nColumns;
	
	BaseType* m;

	union
	{
		struct
		{

		};
	};

	

	Matrix() : nRows(_nRows), nColumns(_nColumns)
	{
		m = new BaseType[nRows*nColumns];
		memset(m, 0, sizeof(BaseType)*nRows*nColumns);
	}

	~Matrix() {delete[] m;}

	//overloaded operators

	//to do: 'out of bounds' check and row/column major order
	BaseType& operator () (unsigned int i, unsigned int j) {return m[nColumns*i + j];}
	BaseType  operator () (unsigned int i, unsigned int j) const {return m[nColumns*i + j];}

	//BaseType& operator = (const baseType& matrix) {}


	//methods

};
*/


//typedef Matrix<float, 2, 2>   Matrix2x2f;
//typedef Matrix<float, 3, 3>   Matrix3x3f;
//typedef Matrix<float, 4, 4>   Matrix4x4f;

/*
class Vector
{
public:

	unsigned int nRows, nColumns;

	Vector();
};


class Vector2f : public Vector
{
	union
	{
		struct
		{
			float x, y;
		};

		float v[2];
	};

	Vector2f()
	{
		Vector()
	}
};

*/
//functions
