#include <fstream> 
#include "Board.hpp"
#include "Hero.hpp"
#include "Warrior.hpp"
#include "Mage.hpp"
#include "Paladin.hpp";
#include <iostream>
using namespace std;
Hero* CreateNewHero() {
	int chooseHero;
	char name[100];
	do
	{
		cout << "Please, select: \n 1 for Warrior \n 2 for Mage \n 3 for Paladin" << endl;
		cin >> chooseHero;
	} while (chooseHero < 1 && chooseHero > 3);
	switch (chooseHero)
	{
	case 1: {
		cout << "You chose Warrior ! Please enter name:" << endl;
		cin.ignore();
		cin.getline(name, 99);
		Hero* h = new Warrior(name);
		return h; break;
	}
	case 2: {
		cout << "You chose Mage ! Please enter name:" << endl;
		cin >> name;
		Hero* h = new Mage(name);
		return h; break;
	}
	case 3: {
		cout << "You chose Paladin ! Please enter name:" << endl;
		cin >> name;
		Hero* h = new Paladin(name);
		return h; break;
	}
	}
}
int main() {
	int optionHero;
	do
	{
	cout << "Please, select: \n 0 for new hero  \n 1 for existing hero" << endl;
	cin >> optionHero;
	} while (optionHero!= 1 && optionHero!= 0);
	switch (optionHero)
	{
	case 0: {
		Board board(CreateNewHero());
		board.GameLoop();
		 break;
	}
	//case 1: LoadHero(); break;
	}
	return 0;
	}
