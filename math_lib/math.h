#include <cmath>


#pragma warning (disable:4305) // truncation from 'double' to 'float'


class Vector2f
{
public:

	static const unsigned int dimension = 2;

	union 
	{
		struct 
		{
			float x, y;
		};

		float v[2];
	};


	// Constructors

	Vector2f() : x(0), y(0) {}

	Vector2f(const float x, const float y) : x(x), y(y) {}

	Vector2f(const float* arr) : x(arr[0]), y(arr[1]) {}

	template <class VecType>
	Vector2f(VecType const &vec) : x(vec.v[0]), y(vec.v[1]) {}


	// Copy

	inline Vector2f& operator = (const Vector2f &vec)
	{
		x = vec.x;
		y = vec.y;
		return *this;
	}


	// Unary operators

	inline Vector2f operator + () const { return *this; }

	inline Vector2f operator - () const { return Vector2f(-x, -y); }


	// Binary operators

	inline Vector2f operator + (const Vector2f& vec) const
	{
		return Vector2f(x + vec.x, y + vec.y);
	}

    inline Vector2f operator - (const Vector2f& vec) const
	{
		return Vector2f(x - vec.x, y - vec.y);
	}

    inline Vector2f operator * (float val) const
	{
		return Vector2f(x*val, y*val);
	}

	inline Vector2f operator * (const Vector2f& vec) const
	{
		return Vector2f(x*vec.x, y*vec.y);
	}

	friend Vector2f operator * (float val, const Vector2f& vec)
	{
		return Vector2f(val * vec.x, val * vec.y);
	}

    inline Vector2f operator / (float val) const
	{
		float invVal = 1.0f/val;
		return Vector2f(x*invVal, y*invVal);
	}


	// Assigment operators

	inline Vector2f& operator += (const Vector2f& vec)
	{
		x += vec.x;
		y += vec.y;
		return *this;
	}

	inline Vector2f& operator -= (const Vector2f& vec)
	{
		x -= vec.x;
		y -= vec.y;
		return *this;
	}

	inline Vector2f& operator *= (const Vector2f& vec)
	{
		x *= vec.x;
		y *= vec.y;
		return *this;
	}

	inline Vector2f& operator *= (float val)
	{
		x *= val;
		y *= val;
		return *this;
	}

	inline Vector2f& operator /= (float val)
	{
		float invVal = 1.0f/val;
		x *= invVal;
		y *= invVal;
		return *this;
	}


	// Methods

	inline float lenght()
	{
		return sqrt(x*x + y*y);
	}

	inline float sqlenght()
	{
		return x*x + y*y;
	}

	Vector2f normalize()
	{
		float lenght = sqrt(x*x + y*y);
		float invLenght;
		if (lenght != 0) 
		{
			invLenght = 1.0f/lenght;
			return Vector2f(x*invLenght, y*invLenght);
		} else {
			return Vector2f(x, y);
		}
	}

	inline float dot(const Vector2f& vec)
	{
		return x*vec.x + y*vec.y;
	}

};


class Vector3f
{
public:

	static const unsigned int dimension = 3;

	union 
	{
		struct 
		{
			float x, y, z;
		};

		float v[3];
	};


	// Constructors 

	Vector3f() : x(0), y(0), z(0) {}

	Vector3f(const float x, const float y, const float z) : x(x), y(y), z(z) {}

	Vector3f(const float* arr) : x(arr[0]), y(arr[1]), z(arr[2]) {}

	Vector3f(Vector2f const &vec, const float z) : x(vec.x), y(vec.y), z(z) {}

	Vector3f(const float x, Vector2f const &vec) : x(x), y(vec.x), z(vec.y) {}

	template <class VecType>
	Vector3f(VecType const &vec) : x(vec.v[0]), y(vec.v[1]), z(vec.v[2]) {}


	// Copy

	Vector3f& operator = (const Vector3f &vec)
	{
		x = vec.x;
		y = vec.y;
		z = vec.z;
		return *this;
	}


	// Unary operators

	inline Vector3f operator + () const { return *this; }

	inline Vector3f operator - () const { return Vector3f(-x, -y, -z); }


	// Binary operators

	inline Vector3f operator + (const Vector3f& vec) const
	{
		return Vector3f(x + vec.x, y + vec.y, z + vec.z);
	}

    inline Vector3f operator - (const Vector3f& vec) const
	{
		return Vector3f(x - vec.x, y - vec.y, z - vec.z);
	}

    inline Vector3f operator * (float val) const
	{
		return Vector3f(x*val, y*val, z*val);
	}

	inline Vector3f operator * (const Vector3f& vec) const
	{
		return Vector3f(x*vec.x, y*vec.y, z*vec.z);
	}

	friend Vector3f operator * (float val, const Vector3f& vec)
	{
		return Vector3f(val * vec.x, val * vec.y, val * vec.z);
	}

    inline Vector3f operator / (float val) const
	{
		float invVal = 1.0f/val;
		return Vector3f(x*invVal, y*invVal, z*invVal);
	}


	// Assigment operators

	inline Vector3f& operator += (const Vector3f& vec)
	{
		x += vec.x;
		y += vec.y;
		z += vec.z;
		return *this;
	}

	inline Vector3f& operator -= (const Vector3f& vec)
	{
		x -= vec.x;
		y -= vec.y;
		z -= vec.z;
		return *this;
	}

	inline Vector3f& operator *= (const Vector3f& vec)
	{
		x *= vec.x;
		y *= vec.y;
		z *= vec.z;
		return *this;
	}

	inline Vector3f& operator *= (float val)
	{
		x *= val;
		y *= val;
		z *= val;
		return *this;
	}

	inline Vector3f& operator /= (float val)
	{
		float invVal = 1.0f/val;
		x *= invVal;
		y *= invVal;
		z *= invVal;
		return *this;
	}


	// Methods

	inline float lenght()
	{
		return sqrt(x*x + y*y + z*z);
	}

	inline float sqlenght()
	{
		return x*x + y*y + z*z;
	}

	Vector3f normalize()
	{
		float lenght = sqrt(x*x + y*y + z*z);
		float invLenght;
		if (lenght != 0) 
		{
			invLenght = 1.0f/lenght;
			return Vector3f(x*invLenght, y*invLenght, z*invLenght);
		} else {
			return Vector3f(x, y, z);
		}
	}

	inline float dot(const Vector3f& vec)
	{
		return x*vec.x + y*vec.y + z*vec.z;
	}
};


class Vector4f
{
public:

	static const unsigned int dimension = 4;

	union 
	{
		struct 
		{
			float x, y, z, w;
		};

		float v[4];
	};


	// Constructors 

	Vector4f() : x(0), y(0), z(0), w(0) {}

	Vector4f(const float x, const float y, const float z, const float w) : x(x), y(y), z(z), w(w) {}

	Vector4f(const float* arr) : x(arr[0]), y(arr[1]), z(arr[2]), w(arr[3]) {}

	Vector4f(Vector2f const &vec, const float z, const float w) : x(vec.x), y(vec.y), z(z), w(w) {}

	Vector4f(const float x, Vector2f const &vec, const float w) : x(x), y(vec.x), z(vec.y), w(w) {}

	Vector4f(const float x, const float y, Vector2f const &vec) : x(x), y(y), z(vec.x), w(vec.y) {}

	Vector4f(Vector3f const &vec, const float w) : x(vec.x), y(vec.y), z(vec.z), w(w) {}

	Vector4f(const float x, Vector3f const &vec) : x(x), y(vec.x), z(vec.y), w(vec.z) {}

	template <class VecType>
	Vector4f(VecType const &vec) : x(vec.v[0]), y(vec.v[1]), z(vec.v[2]), w(vec.v[3]) {}


	// Copy

	Vector4f& operator = (const Vector4f &vec)
	{
		x = vec.x;
		y = vec.y;
		z = vec.z;
		w = vec.w;
		return *this;
	}


	// Unary operators

	inline Vector4f operator + () const { return *this; }

	inline Vector4f operator - () const { return Vector4f(-x, -y, -z, -w); }


	// Binary operators

	inline Vector4f operator + (const Vector4f& vec) const
	{
		return Vector4f(x + vec.x, y + vec.y, z + vec.z, w + vec.w);
	}

    inline Vector4f operator - (const Vector4f& vec) const
	{
		return Vector4f(x - vec.x, y - vec.y, z - vec.z, w - vec.w);
	}

    inline Vector4f operator * (float val) const
	{
		return Vector4f(x*val, y*val, z*val, w*val);
	}

	inline Vector4f operator * (const Vector4f& vec) const
	{
		return Vector4f(x*vec.x, y*vec.y, z*vec.z, z*vec.w);
	}

	friend Vector4f operator * (float val, const Vector4f& vec)
	{
		return Vector4f(val * vec.x, val * vec.y, val * vec.z, val * vec.w);
	}

    inline Vector4f operator / (float val) const
	{
		float invVal = 1.0f/val;
		return Vector4f(x*invVal, y*invVal, z*invVal, w*invVal);
	}


	// Assigment operators

	inline Vector4f& operator += (const Vector4f& vec)
	{
		x += vec.x;
		y += vec.y;
		z += vec.z;
		w += vec.w;
		return *this;
	}

	inline Vector4f& operator -= (const Vector4f& vec)
	{
		x -= vec.x;
		y -= vec.y;
		z -= vec.z;
		w -= vec.w;
		return *this;
	}

	inline Vector4f& operator *= (const Vector4f& vec)
	{
		x *= vec.x;
		y *= vec.y;
		z *= vec.z;
		w *= vec.w;
		return *this;
	}

	inline Vector4f& operator *= (float val)
	{
		x *= val;
		y *= val;
		z *= val;
		w *= val;
		return *this;
	}

	inline Vector4f& operator /= (float val)
	{
		float invVal = 1.0f/val;
		x *= invVal;
		y *= invVal;
		z *= invVal;
		w *= invVal;
		return *this;
	}


	// Methods

	inline float lenght()
	{
		return sqrt(x*x + y*y + z*z + w*w);
	}

	inline float sqlenght()
	{
		return x*x + y*y + z*z + w*w;
	}

	Vector4f normalize()
	{
		float lenght = sqrt(x*x + y*y + z*z + w*w);
		if (lenght != 0) 
		{
			float invLenght = 1.0f/lenght;
			return Vector4f(x*invLenght, y*invLenght, z*invLenght, w*invLenght);
		} else {
			return Vector4f(x, y, z, w);
		}
	}

	inline float dot(const Vector4f& vec)
	{
		return x*vec.x + y*vec.y + z*vec.z + w*vec.w;
	}
};


template <unsigned int _dimension> 
class VectorNf
{
public:

	const unsigned int dimension;

	float* v;


	// Constructors

	VectorNf() : dimension(_dimension)
	{
		//v = (float*)malloc(sizeof(float)*dimension);
		v = new float[dimension];
		memset(v, 0, sizeof(float)*dimension);
	}

	VectorNf(const VectorNf &copy) : dimension(copy.dimension)
	{
		//v = (float*)malloc(sizeof(float)*copy.dimension);
		v = new float[copy.dimension];
		memset(v, 0, sizeof(float)*dimension);
		for(unsigned int i = 0; i < copy.dimension; i++)
		{
			v[i] = copy.v[i];
		}
	}


	// Destructor

	~VectorNf()
	{
		delete[] v;
		//free(v);
	}

	
	// Copy

	VectorNf& operator = (const VectorNf &vec)
	{
		for(unsigned int i = 0; i < dimension; i++)
		{
			v[i] = vec.v[i];
		}
		return *this;
	}


	// Unary operators
 
	VectorNf& operator + () { return *this; }

	VectorNf operator - ()
	{
		VectorNf<_dimension> rVec;
		for(unsigned int i = 0; i < dimension; i++)
		{
			rVec.v[i] = -v[i];
		}
		return rVec;
	}


	// Binary operators

	VectorNf operator + (const VectorNf& vec) const
	{
		VectorNf<_dimension> rVec;
		for(unsigned int i = 0; i < dimension; i++)
		{
			rVec.v[i] = v[i] + vec.v[i];
		}
		return rVec;
	}

	VectorNf operator - (const VectorNf& vec) const
	{
		VectorNf<_dimension> rVec;
		for(unsigned int i = 0; i < dimension; i++)
		{
			rVec.v[i] = v[i] - vec.v[i];
		}
		return rVec;
	}

	VectorNf operator * (float val) const
	{
		VectorNf<_dimension> rVec;
		for(unsigned int i = 0; i < dimension; i++)
		{
			rVec.v[i] = v[i] * val;
		}
		return rVec;
	}

	VectorNf operator * (const VectorNf& vec) const
	{
		VectorNf<_dimension> rVec;
		for(unsigned int i = 0; i < dimension; i++)
		{
			rVec.v[i] = v[i] * vec.v[i];
		}
		return rVec;
	}

	friend VectorNf operator * (float val, const VectorNf& vec)
	{
		VectorNf<_dimension> rVec;
		for(unsigned int i = 0; i < dimension; i++)
		{
			rVec.v[i] = val * vec.v[i];
		}
		return rVec;
	}

    VectorNf operator / (float val) const
	{
		float invVal = 1.0f/val;
		VectorNf<_dimension> rVec;
		for(unsigned int i = 0; i < dimension; i++)
		{
			rVec.v[i] = v[i] * invVal;
		}
		return rVec;
	}


	// Assigment operators

	VectorNf& operator += (const VectorNf& vec)
	{
		for(unsigned int i = 0; i < dimension; i++)
		{
			v[i] += vec.v[i];
		}
		return *this;
	}

	VectorNf& operator -= (const VectorNf& vec)
	{
		for(unsigned int i = 0; i < dimension; i++)
		{
			v[i] -= vec.v[i];
		}
		return *this;
	}

	VectorNf& operator *= (const VectorNf& vec)
	{
		for(unsigned int i = 0; i < dimension; i++)
		{
			v[i] *= vec.v[i];
		}
		return *this;
	}

	VectorNf& operator *= (float val)
	{
		for(unsigned int i = 0; i < dimension; i++)
		{
			v[i] *= val;
		}
		return *this;
	}

	VectorNf& operator /= (float val)
	{
		float invVal = 1.0f/val;
		for(unsigned int i = 0; i < dimension; i++)
		{
			v[i] *= invVal;
		}
		return *this;
	}


	// Methods

	float lenght()
	{
		float sum = 0; //v[0]^2 + v[1]^2 + ...
		for(unsigned int i = 0; i < dimension; i++)
		{
			sum += v[i]*v[i];
		}
		return sqrt(sum);
	}

	float sqlenght()
	{
		float sum = 0;
		for(unsigned int i = 0; i < dimension; i++)
		{
			sum += v[i]*v[i];
		}
		return sum;
	}

	VectorNf normalize()
	{
		float lenght = this->lenght();
		VectorNf<_dimension> rVec;
		if (lenght != 0) 
		{
			float invLenght = 1.0f/lenght;
			for(unsigned int i = 0; i < dimension; i++)
			{
				rVec.v[i] = v[i]*invLenght;
			}
			return rVec;
		} else { //return *this ?
			for(unsigned int i = 0; i < dimension; i++)
			{
				rVec.v[i] = v[i];
			}
			return rVec;
		}
	}

	float dot(const VectorNf& vec)
	{
		float sum = 0;
		for(unsigned int i = 0; i < dimension; i++)
		{
			sum += v[i] * vec.v[i]
		}
		return sum;
	}
};


Vector3f cross(Vector3f inVecA, Vector3f inVecB)
{
	Vector3f outVec;

	outVec.x = inVecA.y * inVecB.z - inVecA.z * inVecB.y;
	outVec.y = inVecA.z * inVecB.x - inVecA.x * inVecB.z;
	outVec.z = inVecA.x * inVecB.y - inVecA.y * inVecB.x;

	return outVec;
}


template <class T>
float dot(T inVecA, T inVecB)
{
	return result = inVecA.dot(inVecB);
}


template <class T>
T normalize(T inVec)
{
	return inVec.normalize();
}



// Matrices

class Matrix2x2f
{
public:

	static const unsigned int nRows = 2, nColumns = 2;

	union
	{
		struct
		{
			float _m00, _m01,
				  _m10, _m11;
		};

		struct
		{
			float _11, _12,
				  _21, _22;
		};

		float m[2][2];

		float mv[4];
	};


	// Constructors

	Matrix2x2f() : _m00(0), _m01(0),
		           _m10(0), _m11(0) {}

	Matrix2x2f(float in_m00, float in_m01,
		       float in_m10, float in_m11) : _m00(in_m00), _m01(in_m01),
		                                     _m10(in_m10), _m11(in_m11) {}


	// Copy

	inline Matrix2x2f& operator = (const Matrix2x2f &mat)
	{
		_m00 = mat._m00;
		_m01 = mat._m01;
		_m10 = mat._m10;
		_m11 = mat._m11;
		return *this;
	}


	// Unary operators

	inline Matrix2x2f operator + () const { return *this; }

	inline Matrix2x2f operator - () const 
	{
		return Matrix2x2f(-_m00, -_m01,
			              -_m10, -_m11);
	}


	// Binary operators

	inline Matrix2x2f operator + (const Matrix2x2f& mat) const
	{
		return Matrix2x2f(_m00 + mat._m00, _m01 + mat._m01,
			              _m10 + mat._m10, _m11 + mat._m11);
	}

    inline Matrix2x2f operator - (const Matrix2x2f& mat) const
	{
		return Matrix2x2f(_m00 - mat._m00, _m01 - mat._m01,
			              _m10 - mat._m10, _m11 - mat._m11);
	}

    inline Matrix2x2f operator * (float val) const
	{
		return Matrix2x2f(_m00 * val, _m01 * val,
			              _m10 * val, _m11 * val);
	}

	friend Matrix2x2f operator * (float val, const Matrix2x2f& mat)
	{
		return Matrix2x2f(mat._m00 * val, mat._m01 * val,
			              mat._m10 * val, mat._m11 * val);
	}

	inline Vector2f operator * (const Vector2f& vec) const
	{
		return Vector2f(_m00*vec.x + _m01*vec.y,
			            _m10*vec.x + _m11*vec.y);
	}

	friend Vector2f operator * (const Vector2f& vec, const Matrix2x2f& mat)
	{
		return Vector2f(vec.x*mat._m00 + vec.y*mat._m10,
			            vec.x*mat._m01 + vec.y*mat._m11);
	}

	inline Matrix2x2f operator * (const Matrix2x2f& mat) const
	{
		Matrix2x2f rMat;

		rMat._m00 = _m00*mat._m00 + _m01*mat._m10;
		rMat._m01 = _m00*mat._m01 + _m01*mat._m11;
		rMat._m10 = _m10*mat._m00 + _m11*mat._m10;
		rMat._m11 = _m10*mat._m01 + _m11*mat._m11;

		return rMat;
	}

	inline Matrix2x2f operator / (float val) const
	{
		float invVal = 1.0f/val;
		return Matrix2x2f(_m00 * invVal, _m01 * invVal,
			              _m10 * invVal, _m11 * invVal);
	}


	// Assigment operators

	inline Matrix2x2f& operator += (const Matrix2x2f& mat)
	{
		_m00 += mat._m00;
		_m01 += mat._m01;
		_m10 += mat._m10;
		_m11 += mat._m11;
		return *this;
	}

	inline Matrix2x2f& operator -= (const Matrix2x2f& mat)
	{
		_m00 -= mat._m00;
		_m01 -= mat._m01;
		_m10 -= mat._m10;
		_m11 -= mat._m11;
		return *this;
	}

    inline Matrix2x2f& operator *= (float val)
	{
		_m00 *= val;
		_m01 *= val;
		_m10 *= val;
		_m11 *= val;
		return *this;
	}

	inline Matrix2x2f& operator *= (const Matrix2x2f& mat)
	{
		_m00 = _m00*mat._m00 + _m01*mat._m10;
		_m01 = _m00*mat._m01 + _m01*mat._m11;
		_m10 = _m10*mat._m00 + _m11*mat._m10;
		_m11 = _m10*mat._m01 + _m11*mat._m11;
		return *this;
	}

	inline Matrix2x2f& operator /= (float val)
	{
		float invVal = 1.0f/val;
		_m00 *= invVal;
		_m01 *= invVal;
		_m10 *= invVal;
		_m11 *= invVal;
		return *this;
	}


	// Methods
	inline Matrix2x2f& setZero()
	{
		_m00 = 0;
		_m01 = 0;
		_m10 = 0;
		_m11 = 0;
		return *this;
	}

	inline Matrix2x2f& setIdentity()
	{
		_m00 = 1.0f;
		_m01 = 0;
		_m10 = 0;
		_m11 = 1.0f;
		return *this;
	}

	inline Matrix2x2f transpose() const
	{
		return Matrix2x2f(_m00, _m10,
			              _m01, _m11);
	} 
};



// Functions

template<class T>
T transpose(T& mat)
{
	return mat.transpose();
}