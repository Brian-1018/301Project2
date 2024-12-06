#ifndef ENIGMA_H
#define ENIGMA_H
#include <string>
#include "Rotor.h"

class Enigma
{
private:
    static std::string POSSIBLE[5];
    Rotor inner;
    Rotor middle;
    Rotor outer;

public:
    Enigma(int inner_wheel, int middle_wheel, int outer_wheel, std::string tops); //the constructor
    std::string encrypt(std::string message);
    std::string decrypt(std::string message);
    void resetEnigma();
};

#endif