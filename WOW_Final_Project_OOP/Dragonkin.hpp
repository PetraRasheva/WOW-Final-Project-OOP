#pragma once
#include "Monster.hpp"
class Dragonkin : virtual public Monster
{
public:
	Dragonkin();
	int Attack(int = 0);
	void Defend(int);
	char getType() const;

private:
	char type = 'D';
	int numDefends = 1;

};
Dragonkin::Dragonkin() : Monster() {
	HP = 30;
}
int Dragonkin::Attack(int a) {
	return 8;
}
//Всяка трета защита намаля щетите, които получава със 10
void Dragonkin::Defend(int damage) {
	if (numDefends % 3 == 0) {
		damage -= 10;
		if (damage < 0) damage = 0;
		HP -= (damage / 2);
		numDefends++;
	}
	else {
		HP -= (damage /2) ;
		numDefends++;
	}
}
char Dragonkin::getType() const {
	return type;
}




