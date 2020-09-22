#pragma once
#include <iostream>
class Hero
{
public:
	Hero(const char*);
	Hero(const Hero&);
	Hero& operator=(const Hero&);
	~Hero();


	int getHP();
	int getX();
	int getY();
	char* getName();

	void setX(const int);
	void setY(const int);
	void setHP(const int);
	void Move(char);
	void LevelUp();

	virtual int Attack() = 0;
	virtual void Defend(int) = 0;
	virtual char getType() = 0;
	void leavesBattle();

protected:
	char* name;
	int HP;
	int strength;
	int intellect;
	int level;
	int x;
	int y;
	int kills;
	bool inBattle;

	void CopyFrom(const Hero&);
	void Free();

};
void Hero::CopyFrom(const Hero& other) {
	this->name = new char[strlen(other.name) + 1];
	strcpy(this->name, other.name);
	this->HP = other.HP;
	this->strength = other.strength;
	this->intellect = other.intellect;
	this->level = other.level;
	this->x = other.x;
	this->y = other.y;
	this->kills = other.kills;
	this->inBattle = other.inBattle;
}

void Hero::Free() {
	delete[] name;
}

Hero::Hero(const char * _name)
{
	name = new char[strlen(_name) + 1];
	strcpy(name, _name);
	HP = 100;
	level = 0;
	kills = 0;
	x = 0;
	y = 0;
	inBattle = false;
}

Hero::Hero(const Hero& other) {
	CopyFrom(other);
}

Hero& Hero::operator=(const Hero& other) {
	if (this != &other) {
		Free();
		CopyFrom(other);
	}
	return *this;
}

Hero::~Hero()
{
	Free();
}

void Hero::LevelUp() {
	if (kills == 2 * level) {
		level++;
		HP += ( HP / 100 ) * 10;
		strength += strength / 3;
	}
}

void Hero::Move(char direction) {
	
	switch (direction)
	{
	case 'w': {
			x -= 1;
			break;
		}
	case 's': {
			x += 1;
			break;
		}
	case 'a': {
			y -= 1;
			break;
		}
	case 'd': {
			y += 1;
			break;
		}
	}
}

int Hero::getHP() {
	return HP;
}

void Hero::setHP(const int newHP) {
	HP = newHP;
}

int Hero::getX()
{
	return x;
}

void Hero::setX(const int X) {
	this->x = x;
}

int Hero::getY()
{
	return y;
}

void Hero::setY(const int y) {
	this->y = y;
}

char* Hero::getName() {
	return name;
}

void Hero::leavesBattle() {
	inBattle = false;
}