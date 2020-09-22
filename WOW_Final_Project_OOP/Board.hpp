#pragma once
#include <iostream>
#include "Monster.hpp"
#include "Hero.hpp"
#include "DeathKnight.hpp"
using namespace std;
const size_t len = 9;
class Board 
{
private:
	Monster*** board;
	Hero* hero;
public:
	Board(Hero*);
	Board() {};
	Board(const Board& other) = delete;
	Board& operator=(const Board& other) = delete;
	~Board();

	void init();
	void processInput();
	bool isValidMove(char);
	void Battle();
	void drawBoard();
	void printName(char);
	void GameLoop();
};
Board::Board(Hero* heroPtr)
{
	hero = heroPtr;
	init();
}
void Board::init() {
		board = new Monster**[len];
		for (int i = 0; i < len; ++i)
			board[i] = new Monster*[len];

		for (int i = 0; i < len ; i++) {
			for (int j = 0; j < len; j++) {
					int index = rand() % 5;
				switch (index)
				{
				case 1: board[i][j] = new Goblin(); break;
				case 2: board[i][j] = new Dragonkin(); break;
				case 3: board[i][j] = new DeathKnight(); break;
				default: board[i][j] = nullptr; break;
				}
			}
		}
}
Board::~Board() {
		for (int i = 0; i < len; ++i)
		{
			for (int j = 0; j < len; ++j)
			{
				delete board[i][j];
			}
			delete[] board[i];
		}
		delete[] board;
		delete hero;
}

bool Board::isValidMove(char dir) {
	int x = hero->getX();
	int y = hero->getY();
	switch (dir)
	{
		// x -> up/down y -> left/right
	case 'w':  return (x > 0); break;
	case 's': return (x < len - 1); break;
	case 'a': return (y > 0); break;
	case 'd': return (y < len - 1); break;
	case 'e': throw "You just exit the game. "; break;
	}
}

void Board::drawBoard() {
	for (int i = 0; i < len; i++)
	{
		for (int j = 0; j < len; j++) {
			if (i == hero->getX() && j == hero->getY()) {
				cout << hero->getType();
			}
			else {
				if (board[i][j] == nullptr) cout << " ";
				else {
					cout << board[i][j]->getType();
				}
			}
		}
		cout << endl;
	}
}
void Board::printName(char type) {
	switch (type)
	{
	case 'D': cout << "Dragonkin" << endl; break;
	case 'G': cout << "Goblin" << endl;; break;
	case 'K': cout << "Death Knight" << endl; break;
	}
}

void Board::GameLoop() {
	while (true)
	{
		drawBoard();
		processInput();
	}
}
void Board::processInput() {
	//choose direction
	cout << "---------------------------------" << endl;
	cout << endl;
	cout << "To move hero,  use w a s d \n Press 'e' to EXIT... " << endl;
	char dir;
	cout << endl;
	do
	{
		cout << "> ";
		cin >> dir;
		if(!isValidMove(dir)) cout << "End of map, try new direction." << endl;
		cout << "---------------------------------" << endl;
	} while (!isValidMove(dir));
	hero->Move(dir);
	//move hero
	if (board[hero->getX()][hero->getY()] != nullptr) {
			Battle();
	}
}
void Board::Battle() {
	int x = hero->getX();
	int y = hero->getY();
	while (hero->getHP() > 0) {
		board[x][y]->Defend(hero->Attack());
		if (board[x][y]->getHP() <= 0) {
			cout << hero->getName() << ", you just killed ";
			printName(board[x][y]->getType());
			cout << "---------------------------------" << endl;
			delete board[x][y];
			board[x][y] = nullptr;
			hero->leavesBattle();
			return;
		}
		else {
			hero->Defend(board[x][y]->Attack());
			if (hero->getHP() <= 0) {
				cout << "GAME OVER" << endl;
				return;
			}
		}
	}
}

