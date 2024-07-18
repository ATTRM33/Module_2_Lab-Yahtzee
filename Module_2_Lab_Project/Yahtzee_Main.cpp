// Zach Brown
//Date: 7/17/2024
//CS2 Yahtzee

#include <iostream>
#include <ctime>
#include <string>
#include <vector>
#include "Die.h"
#include "GameLogic.h"
#include "ConsoleUI.h"
#include <iostream>


using namespace std;


int main() {
	//object instantiation
	ConsoleUI ui;
	
	//random seed
	std::srand(std::time(0));
	
	//run the program as much as you would like
	while (true)
	 {
		//ui object runs the game
		ui.displayWelcome();

		
	}
	
}
