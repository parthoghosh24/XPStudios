#pragma once

/*
* A simple Vector library which could perform all vector operations.
* We could use this to implement all the assets in the game which needs to be moved.
* Since this is 2D vectors, we don't have a cross product here.
*/
struct Vector 
{
	float mX;

	float mY;

	Vector(float x, float y);

	Vector() = delete; // Default constructor not allowed for vector

	Vector Add(const Vector& other) const;

	Vector Subtract(const Vector& other) const;	

	
	float Dot(const Vector& other) const;

	void Scale(float scaleFactor);

	void normalize();


};
