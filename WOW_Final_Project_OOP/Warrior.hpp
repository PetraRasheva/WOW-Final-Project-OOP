#pragma once
#include "Hero.hpp"
class Warrior : public Hero
{
public:
	Warrior(const char*);
	void Defend(int);
	char getType();
	int Attack();
private:
	char type = 'W';
	int rage;
};

Warrior::Warrior(const char* name) : Hero(name)
{
	strength = 13;
	intellect = 2;
	rage = 0;
}

int Warrior::Attack() {
	if (!inBattle) rage = 0;
	inBattle = true;
	if (rage >= 10) {
		if (rage <= 98)rage += 2;
		return (strength + (3 / 10) * intellect) + (strength + (3 / 10) * intellect) * (rage / 5);
	}
	else {
		rage += 2;
		return (strength + (3 / 10) * intellect);
	}
	
}

void Warrior::Defend(int damage) {
	if (rage <= 97)rage += 3;
	HP -= (damage /5);
	if (HP < 0)HP = 0;
}

char Warrior::getType() {
	return type;
}

