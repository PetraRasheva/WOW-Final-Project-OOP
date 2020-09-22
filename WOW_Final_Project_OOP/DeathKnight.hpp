#pragma once
#include "Goblin.hpp"
#include "Dragonkin.hpp"

//3. Death Knight​ - Това е чудовище породено от Goblin и Dragonkin. Редува атаките на двете чудовища, а се защитава като Dragonkin.  
class DeathKnight :  public Dragonkin , public Goblin
{
public:
	DeathKnight();
	char getType() const;
	int Attack(int = 0);
	void Defend(int);

private:
	char type = 'K';
	int numAttacks = 1;
};

DeathKnight::DeathKnight() : Dragonkin(), Goblin()
{
	HP = 10;
}

int DeathKnight::Attack(int intellect) {
	if (numAttacks % 2 == 0) {
		return Goblin::Attack(intellect);
	}
	else {
		return Dragonkin::Attack();
	}
	numAttacks++;
}

void DeathKnight::Defend(int damage) {
	Dragonkin::Defend(damage);
}

char DeathKnight::getType() const {
	return type;
}

