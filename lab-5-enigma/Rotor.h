#ifndef ROTOR_H
#define ROTOR_H
#include <string>

class Rotor
{
// private so hidden, the member variables and a validity checker we don't want to be accessed
private:
    std::string wheel; // the circular rotor string
    char top; // the cracter at the top of the wheel
// public, so when using the Rotor these can be accessed
public:
    Rotor(std::string initialWheel, char initialTop); // constructor
    void reset(); //resets the rotor so the top character is on top
    void rotateCC(); // rotates one click clockwise
    int giveIndex(char character); // Returns the index in the wheel where a given character is located
    char giveCharacter(int index); // Returns the character in the wheel at a given index
    std::string getWheel(); //gets the wheel
    char getTop(); // gets the perma-top
};

#endif