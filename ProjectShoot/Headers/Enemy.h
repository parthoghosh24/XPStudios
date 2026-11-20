#pragma once
#include <IHitable.h>
#include <Vector.h>

class Enemy: public Ihitable
{
public:
	Enemy();
	~Enemy() = default;

private:
	int mHealth;
	Vector mPosition;

	
};
