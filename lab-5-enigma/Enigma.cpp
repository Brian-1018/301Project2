#include "Enigma.h"
#include <string>
using namespace std;

string Enigma::POSSIBLE[5] = {"#GNUAHOVBIPWCJQXDKRYELSZFMT",
 "#EJOTYCHMRWAFKPUZDINSXBGLQV", "#BDFHJLNPRTVXZACEGIKMOQSUWY",
 "#NWDKHGXZVRIFJBLMAOPSCYUTQE", "#TGOWHLIFMCSZYRVXQABUPEJKND"}; //the five possible wheels

/**
 * Constructs three rotors based on input of which five wheels, and which should be on top
*/
Enigma::Enigma(int inner_wheel, int middle_wheel, int outer_wheel, string tops)
    : inner{Rotor(POSSIBLE[inner_wheel-1], tops[0])},
      middle{Rotor(POSSIBLE[middle_wheel-1], tops[1])}, 
      outer{Rotor(POSSIBLE[outer_wheel-1], tops[2])}
{
}

/**
 * resets all rotors in the enigma
*/
void Enigma::resetEnigma()
{
    inner.reset();
    middle.reset();
    outer.reset();
}

/**
 * 
*/
string Enigma::encrypt(string message)
{
    string finished_message;
    for (long unsigned int i = 0; i< message.size(); i++)
    {
        // encrypts the letter of the message
        char in_message = message[i];
        int idx_in_message = inner.giveIndex(in_message);
        char out_message = outer.giveCharacter(idx_in_message);
        int idx_mid_message = middle.giveIndex(out_message);
        finished_message += outer.giveCharacter(idx_mid_message);

        // rotates the wheel, each level if necessary
        inner.rotateCC();
        if (inner.getWheel()[0] == inner.getTop())
        {
            middle.rotateCC();
            if (middle.getWheel()[0] == middle.getTop())
            {
                outer.rotateCC();
            }
        }

    }
    return finished_message;
}

/**
 * 
 * 
*/
string Enigma::decrypt(string message)
{
    string finished_message;
    for (long unsigned int i = 0; i< message.size(); i++)
    {
        char out_message = message[i];
        int idx_out_message = outer.giveIndex(out_message);
        char mid_message = middle.giveCharacter(idx_out_message);
        int idx_outer_message = outer.giveIndex(mid_message);
        finished_message += inner.giveCharacter(idx_outer_message);

        inner.rotateCC();
        if (inner.getWheel()[0] == inner.getTop())
        {
            middle.rotateCC();
            if (middle.getWheel()[0] == middle.getTop())
            {
                outer.rotateCC();
            }
        }

    }
    return finished_message;
}