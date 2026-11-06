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

	Vector Add(Vector& other);

	Vector Subtract(Vector& other);	

	
	float Dot(Vector& other);

	void Scale(float scaleFactor);


};
