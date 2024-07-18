#ifndef DIE_H
#define DIE_H

#include <string>

class Die {
private:
    int numSides;
    int faceValue;

public:
    Die(int sides = 6);
    void roll();
    int getFaceValue() const;
    std::string dieToString() const;
};

#endif // DIE_H
