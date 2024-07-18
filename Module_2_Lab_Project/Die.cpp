#include "Die.h"
#include <cstdlib>
#include <ctime>
#include <string>

Die::Die(int sides) : numSides(sides), faceValue(1) {
    
}

void Die::roll() {
    //generates a random number based of numSides
    faceValue = std::rand() % numSides + 1;
}

int Die::getFaceValue() const {
    return faceValue;
}

std::string Die::dieToString() const {
    return "A " + std::to_string(numSides) + "-sided Die showing a " + std::to_string(faceValue);
}