#pragma once
#include <iostream>
class Monster 
{
public:
	Monster();
	virtual ~Monster() {};
	virtual int Attack(int = 0) = 0;
	virtual void Defend(int) = 0;
	virtual char getType() const = 0;

	void setHP(const int);
	int getHP();

protected:
	int HP;
	int strength;
	//int x;
	//int y;
};

Monster::Monster()
{
	strength = 1;
	//x = _x;
	//y = _y;
}

int Monster::getHP() {
	return HP;
}

void Monster::setHP(const int newHP) {
	HP = newHP;
}

