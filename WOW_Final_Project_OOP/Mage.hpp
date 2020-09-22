#pragma once
#include "Hero.hpp";
// Разчита на магиите. Всеки магьосник започва с 4 сила и 11 интелект и 100 мана. Това са точки, които отговарят за силата на магиите.
//Атакува по следната формула (интелект + (мана/100)*3). След всяка атака магьосника губи 10 от маната си
//и започва всяка битка със 100
class Mage : public Hero
{
public:
	Mage(char*);
	int Attack();
	void Defend(int);
	char getType();
	void restoreMana();

private:
	char type = 'M';
	int mana;
};

Mage::Mage(char* name) : Hero(name)
{
	strength = 4;
	intellect = 11;
	mana = 100;
}

int Mage::Attack() {
	if (!inBattle)mana = 110;
	inBattle = true;
	mana -= 10;
	return intellect + (mana / 100) * 3;
}

void Mage::Defend(int damage) {
	HP -= (damage / 4);
}

char Mage::getType() {
	return type;
}
