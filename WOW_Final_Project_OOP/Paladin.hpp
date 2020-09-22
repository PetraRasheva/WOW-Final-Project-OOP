#pragma once
#include "Hero.hpp"
class Paladin : public Hero
{
public:
	Paladin(const char*);
	void Defend(int);
	char getType();
	int Attack();
private:
	char type = 'P';
	int numAttacks = 1;
};

Paladin::Paladin(const char* name) : Hero(name)
{
	strength = 9;
	intellect = 6;
}

int Paladin::Attack() {
	int power = strength * (50 / 100);
	if (numAttacks % 3 == 0) {
		power += (50 / 100) * power;
	}
	return power;
}

void Paladin::Defend(int damage) {
	HP -= (damage / 10);
}

char Paladin::getType() {
	return type;
}
