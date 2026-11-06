#include "Vector.h"

Vector::Vector(float x, float y): mX(x), mY(y) // Vector constructor
{
}

Vector Vector::Add(Vector& other)
{
	return Vector(mX + other.mX, mY + other.mY);
}

Vector Vector::Subtract(Vector& other)
{
	return Vector(mX - other.mX, mY - other.mY);
}

float Vector::Dot(Vector& other)
{
	return mX * other.mX + mY * other.mY;
}

void Vector::Scale(float scaleFactor)
{
	mX *= scaleFactor;
	mY *= scaleFactor;
}
