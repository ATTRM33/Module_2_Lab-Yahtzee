#pragma once
#ifndef CONSOLE_UI
#define CONSOLE_UI

#include <vector>
#include "Die.h"

class ConsoleUI
{
private:
	char startgame;

public:
	void displayWelcome();
	void startGame(bool newGame);
	std::vector<int> promptReroll();
	void displayDice(const std::vector<Die>& dice);
	int promptChooseScore();
	
};
#endif

