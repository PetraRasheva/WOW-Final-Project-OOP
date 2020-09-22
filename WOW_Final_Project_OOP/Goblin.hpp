#pragma once
#include "Monster.hpp"
class Goblin : virtual public Monster
{
public:
	Goblin();
	int Attack(int);
	void Defend(int);
	char getType() const;
private :
	char type = 'G';
};

Goblin::Goblin() : Monster() {
	HP = 10;
}

int Goblin::Attack(int intellect) {

	return 3 + intellect * (10/100);
}

void Goblin::Defend(int damage) {
	HP -= (damage / 3);
}

char Goblin::getType() const {
	return type;
}
