#pragma once
#include "Hero.hpp";
// ������� �� �������. ����� ��������� ������� � 4 ���� � 11 �������� � 100 ����. ���� �� �����, ����� ��������� �� ������ �� �������.
//������� �� �������� ������� (�������� + (����/100)*3). ���� ����� ����� ���������� ���� 10 �� ������ ��
//� ������� ����� ����� ��� 100
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
