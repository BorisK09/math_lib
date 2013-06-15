#include <cmath>

class Vector2
{
public:

	union 
	{
    	struct
		{
			float x, y;
		};

		float v[2];
	};

	static const int nColumns = 2, nRows = 1;

	//constructors
	Vector2();
	Vector2(float _x, float _y);
	//initialisation with array

	//unary operators
	Vector2 operator + () const;
	Vector2 operator - () const;

	//binary operators
	Vector2 operator + (const Vector2& _vec2) const;
	Vector2 operator - (const Vector2& _vec2) const;
	Vector2 operator * (float _val) const;			//Vector2 * float = Vector2 (scale)
	float   operator * (const Vector2& _val) const;	//Vector2 * Vector2 = float (dot product)
	Vector2 operator / (float _val) const;

	//assignment operators
	Vector2& operator += (const Vector2& _vec2);
	Vector2& operator -= (const Vector2& _vec2);
	Vector2& operator *= (float _val);
	Vector2& operator /= (float _val);

	friend Vector2 operator * (float _val, const Vector2& _vec2);  //float * Vector2 = Vector2 (scale)

	//methods
	Vector2 set(float _x, float _y);
	Vector2 normalize();
private:
};


Vector2::Vector2()
{
	x = 0.0;
	y = 0.0;
}

Vector2::Vector2(float _x, float _y)
{
	x = _x;
	y = _y;
}

Vector2 Vector2::operator + () const
{
	return *this;
}

Vector2 Vector2::operator - () const
{
	return Vector2(-x, -y);
}

Vector2 Vector2::operator + (const Vector2& _vec2) const
{
	Vector2 retV2;
	retV2.x = x + _vec2.x;
	retV2.y = y + _vec2.y;
	return retV2;
}

Vector2 Vector2::operator - (const Vector2& _vec2) const
{
	Vector2 retV2;
	retV2.x = x - _vec2.x;
	retV2.y = y - _vec2.y;
	return retV2;
}

Vector2 Vector2::operator * (float _val) const
{
	Vector2 retV2;
	retV2.x = x * _val;
	retV2.y = y * _val;
	return retV2;
}

float Vector2::operator * (const Vector2& _vec2) const
{
	float result = x*_vec2.x + y*_vec2.y;
	return result;
}

Vector2 Vector2::operator / (float _val) const
{
	Vector2 retV2;
	retV2.x = x / _val;
	retV2.y = y / _val;
	return  retV2;
}

Vector2& Vector2::operator += (const Vector2& _vec2)
{
	x += _vec2.x;
	y += _vec2.y;
	return *this;
}

Vector2& Vector2::operator -= (const Vector2& _vec2)
{
	x -= _vec2.x;
	y -= _vec2.y;
	return *this;
}

Vector2& Vector2::operator *= (float _val)
{
	x *= _val;
	y *= _val;
	return *this;
}

Vector2& Vector2::operator /= (float _val)
{
	x /= _val;
	y /= _val;
	return *this;
}

Vector2 operator * (float _val, const Vector2& _vec2)
{
    return Vector2(_val * _vec2.x, _val * _vec2.y);
}

Vector2 Vector2::normalize()
{
	double lenght = sqrt(x*x + y*y);
	//warning: if "length" = 0 then "division by zero" situation
	float invLength = float(1.0/lenght);
	Vector2 retV2(x*invLength, y*invLength);
	return retV2;
}



class Matrix
{

};



template <class T>
T add(T a, T b)
{
	T result = a + b;
	return result;
}

template <class T>
T sub(T a, T b)
{
	T result = a - b;
	return result;
}

template <class T>
T scale(T a, float factor)
{
	T result = a * factor;
	return result;
}

template <class T>
T normalize(T a)
{
	T result = a.normalize();
	return result;
}

template <class T>
float dot(T a, T b)
{
	return a * b;
}

template <class T>
float distance(T a, T b)
{
	return 0.0;
}