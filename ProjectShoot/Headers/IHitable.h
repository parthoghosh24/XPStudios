#pragma once
class Ihitable {
public:
	virtual ~Ihitable() = default;

	virtual void TakeDamage(int damage) = 0;
};