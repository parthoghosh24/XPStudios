#pragma once
struct WeaponType
{
	
};

class Weapon {
protected:
	int WeaponPower;

public:
	virtual ~Weapon() = default;
	void dealDamage(Ihitable& target);

};