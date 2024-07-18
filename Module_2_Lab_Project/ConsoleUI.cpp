#include "ConsoleUI.h"
#include "Die.h"
#include "GameLogic.h"
#include <iostream>
#include <string>


void ConsoleUI:: displayWelcome() {


	int selection;
	char goBack;
		
		//system menu
		std::cout << "***Welcome to Yahtzee**\n \n";
		std::cout << "Choose from the following\n";
		std::cout << "1. New Game \n";
		std::cout << "2. Rules \n";
		std::cout << "3. Quit Game \n";

		std::cin >> selection;

		switch (selection)
		{
		case 1:
			system("cls");
			ConsoleUI::startGame(true);
			break;
		case 2:
			system("cls");
			//display rules for user
			std::cout << "***Rules***\n";
			std::cout << "\n1. In this game you will play six rounds of rolling 5 dice. \n";
			std::cout << "2. After each roll you can choose what die you wish to keep and which you would like to re - roll. \n";
			std::cout << "3. After each round you may score the dice you have in 1s, 2s, 3s, 4s, 5s, or 6s. You may only score 1 type per game.\n";
			std::cout << "4. Points are the face value of the dice rolled\n";
			std::cout << "5. The goal is to have the highest points possible after six rounds \n";
			std::cout << "\n Press Y to return to the main menu\n";
			std::cin >> goBack;
			
			system("Cls");
			break;
		case 3:
			std::cout << "Thank you for playing Yahtzee! Goodbye. \n";
			
			exit(0);
		default:
			//data validation
			std::cout << "Invalid selection. Please choose a valid option.\n";
			break;
		}
	 
}

void ConsoleUI::displayDice(const std::vector<Die>& dice) {
	//for loop that displays each die roll in the vector
	for (const Die& die : dice) {
		std::cout << die.dieToString() << std::endl;
	}
}

void ConsoleUI::startGame(bool newGame) {
	if (newGame) {
		GameLogic game;

		for (int round = 1; round <= 6; round++) {
			for (int diceRound = 1; diceRound <= 3; ++diceRound) {
				system("cls");

				//user information for round, roll and score
				std::cout << "--ROUND-- " << round << "\n";
				std::cout << "--ROLL-- " << diceRound << "\n";
				std::cout << "SCORE: " << game.getTotalScore() << std::endl;

				//only rolls all dice if its first round
				if (diceRound == 1) {
					game.rollDice();
				}

				//display current dice
				displayDice(game.getDice());


				//get the dice to re-roll from the user
				if (diceRound < 3) {
					std::vector<int> rerollIndices = promptReroll();
					game.rerollDice(rerollIndices);
				}
			}

			int scoreChoice;
			do {
				//takes users scoring method and stores it each round
				scoreChoice = promptChooseScore();

			} while (game.isScoringUsed(scoreChoice));

			game.getRoundScore(scoreChoice);
		}
		system("cls");
		std::cout << "--GAME OVER-- " << std::endl; 
		std::cout << "FINAL SCORE: " << game.getTotalScore() << std::endl;
	}
}
std::vector<int> ConsoleUI::promptReroll() {
	std::vector<int> rerollIndices;
	int index;

	//prompt for stroing the index value(s) the user chooses
	std::cout << "Enter the indices of the dice you want to re-roll (0-4), separated by spaces. Enter -1 to stop:\n";
	while (true) {
		std::cin >> index;
		//allows user to break the loop after indices are chosen
		if (index == -1) {
			break;
		}
		if (index >= 0 && index < 5) {
			rerollIndices.push_back(index);
		}
		else {
			std::cout << "Invalid index. Please enter a number between 0 and 4, or -1 to stop.\n";
		}
	}

	return rerollIndices;
}

int ConsoleUI::promptChooseScore() {
	int selection;

	//decide which method to score by and return the value to selection
	std::cout << "Which dice do you want to score?: \n";
	std::cout << "1. 1s\n";
	std::cout << "2. 2s\n";
	std::cout << "3. 3s\n";
	std::cout << "4. 4s\n";
	std::cout << "5. 5s\n";
	std::cout << "6. 6s\n";
	std::cin >> selection;

	return selection;

	
}




