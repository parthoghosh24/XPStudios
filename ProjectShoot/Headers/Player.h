#pragma once
#include "Vector.h"
#include "Ihitable.h"
#include "Weapon.h"


class Player : public Ihitable {
public:
	Player();
	~Player() = default;
	void move(const Vector& direction, float deltaTime);
	Vector getPosition() const;
	int getHealth() const;
	void TakeDamage(int damage) override;
	void renderPlayer(const Vector& position);
	

private:
	int health;
	Vector position;
	float movementSpeed;
	float hitBoxRadius;
	Weapon* weapon;

};