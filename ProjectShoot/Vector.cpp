#include "Vector.h"
#include <cmath>

Vector::Vector(float x, float y): mX(x), mY(y) // Vector constructor
{
}

Vector Vector::Add(const Vector& other) const
{
	return Vector(mX + other.mX, mY + other.mY);
}

Vector Vector::Subtract(const Vector& other) const
{
	return Vector(mX - other.mX, mY - other.mY);
}

float Vector::Dot(const Vector& other) const
{
	return mX * other.mX + mY * other.mY;
}

void Vector::Scale(float scaleFactor)
{
	mX *= scaleFactor;
	mY *= scaleFactor;
}

void Vector::normalize()
{
	float magSq = (mX * mX) + (mY * mY);
	if (magSq > 0.0f) 
	{
		float invMag = 1.0f / std::sqrt(magSq);
		mX *= invMag;
		mY *= invMag;
	}
}
