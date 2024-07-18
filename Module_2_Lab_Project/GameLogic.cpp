#include "GameLogic.h"
#include <iostream>

GameLogic::GameLogic() : baseScore(0) {
    //generate a 5 die with basescore of 6 
    for (int i = 0; i < 5; ++i) {
        dice.push_back(Die(6));
    }
}

void GameLogic::rollDice() {
    //rolls the given die in the array
    for (Die& die : dice) {
        die.roll();
    }
}

void GameLogic::rerollDice(const std::vector<int>& diceIndices) {
    //loops through a vector of indices chosen by user and rolls the dice associated with that integer
    for (int index : diceIndices) {
        if (index >= 0 && index < dice.size()) {
            dice[index].roll();
        }
    }
}

std::vector<Die> GameLogic::getDice() const {
    return dice;
}

void GameLogic::getRoundScore(int selection) {

    //if the user has already used a scoring method
    if (isScoringUsed(selection)) {
        std::cout << "Scoring for " << selection << " has already been used." << std::endl;
    }

    //score the dice based on the selection made by the user
    int selectionScore = 0;
    for (Die& die : dice) {

        //face value of die is associated with user selection
        if (die.getFaceValue() == selection) {
            selectionScore += selection;
        }
    }

    addRoundScore(selectionScore);
    
    //marks the selection as used
    usedScoring[selection - 1] = true;
}

int GameLogic::getTotalScore() const {
    //takes all score stored within roundScore and adds them to a running total
    int total = 0;
    for (int roundScore : roundScores) {
        total += roundScore;
    }
    return total;
}

void GameLogic::addRoundScore(int roundScore) {
    //takes the score from each round and stores them in an vector
    roundScores.push_back(roundScore);
}

bool GameLogic::isScoringUsed(int selection) const {
    if (selection < 1 || selection > 6) {
        return true; 
    }
    return usedScoring[selection - 1];
}