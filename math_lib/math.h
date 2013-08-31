#include <cmath>


#pragma warning (disable:4305) // truncation from 'double' to 'const float'


class Vector2f
{
public:

	static const unsigned int dimention = 2;

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

	static const unsigned int dimention = 3;

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

	static const unsigned int dimention = 4;

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


template <unsigned int _dimention> 
class VectorNf
{
public:

	const unsigned int dimention;

	float* v;


	// Constructors

	VectorNf() : dimention(_dimention)
	{
		//v = (float*)malloc(sizeof(float)*dimention);
		v = new float[dimention];
		memset(v, 0, sizeof(float)*dimention);
	}

	VectorNf(const VectorNf &copy) : dimention(copy.dimention)
	{
		//v = (float*)malloc(sizeof(float)*copy.dimention);
		v = new float[copy.dimention];
		memset(v, 0, sizeof(float)*dimention);
		for(unsigned int i = 0; i < copy.dimention; i++)
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
		for(unsigned int i = 0; i < dimention; i++)
		{
			v[i] = vec.v[i];
		}
		return *this;
	}


	// Unary operators
 
	VectorNf& operator + () { return *this; }

	VectorNf operator - ()
	{
		VectorNf<_dimention> rVec;
		for(unsigned int i = 0; i < dimention; i++)
		{
			rVec.v[i] = -v[i];
		}
		return rVec;
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
