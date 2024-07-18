#ifndef GAMELOGIC_H
#define GAMELOGIC_H

#include "Die.h"
#include <vector>

class GameLogic {
private:
    std::vector<Die> dice;
    std::vector<int> roundScores;
    int baseScore;
    int roundScore;
    bool usedScoring[6];

public:
    GameLogic();
    void rollDice(); 
    void rerollDice(const std::vector<int>& diceIndices);
    std::vector<Die> getDice() const;
    void getRoundScore(int selection);
    int getTotalScore() const;
    void addRoundScore(int roundScore);
    bool isScoringUsed(int selection) const;
   
};

#endif // GAMELOGIC_H
