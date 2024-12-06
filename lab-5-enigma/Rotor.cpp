#include "Rotor.h"
#include <string>
using namespace std;

/**
 * @param initialWheel a string to be the characters of the Rotor
 * @param initialTop a string the be the character at the top of the rotor
 * 
*/
Rotor::Rotor(string initialWheel, char initialTop) //constructor
    : wheel{initialWheel}, top{initialTop} // member initializer list
{
    reset();
}

/**
 * Rotates the wheel by 1 click clockwise
*/
void Rotor::rotateCC()
{
    // sends the character at the end of the string to the beginning, essentially rotating it
    for (int i = 26; i>0; i--)
    {
        char temp = wheel[i];
        wheel[i] = wheel[i-1];
        wheel[i-1] = temp;
    }
}

/**
 * @param index an int for which character in the wheel you want
 * @return the character at that location
 * finds the character at a given spot in the wheel
*/
char Rotor::giveCharacter(int index)
{
    return wheel[index];
}

/**
 * @param character a char to be found in the wheel
 * @return the index of the character in the wheel
 * finds a character in the wheel's index
*/
int Rotor::giveIndex(char character)
{
    return wheel.find(character);
}

/**
 * @return the wheel member
*/
string Rotor::getWheel()
{
    return wheel;
}

/**
 * @return the top member
*/
char Rotor::getTop()
{
    return top;
}

/**
 * Rotates the wheel until the top is on top
*/
void Rotor::reset()
{
    while (wheel[0] != top)
    {
        rotateCC();
    }
}