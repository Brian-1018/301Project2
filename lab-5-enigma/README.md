# Lab 4 Classes

### Objectives

Practice object-oriented programming and design by exploring C++ classes using encapsulation, and data hiding via abstraction.

See course web page [lab4](https://cmsc240-f23.github.io/lab/4) for the full directions.


## Describe your work

Please provide a short description of each of the C++ classes you completed in this lab
- Rotor: has a string  with 27 characters that can rotate, and has one of them set to be the top character, and it resets back to than when needed
- Enigma: Uses three Rotors and predefined strings for them to encode and decode messages based on the alignments and rotations.

## Rotor.cpp

Use the space below to describe the object oriented design applied with respect to data hiding and encapsulation
- It has a private variables that are hidden for the wheel string, and the top char in that string.
- The constructor and all the functions are public, including getters, so they can be accessed by the other files/classes
## Enigma.cpp

Use the space below to describe the object oriented design applied with respect to data hiding and encapsulation
- It has a set of static private variables for the possible Rotor strings could be
- It also has three member variables of the Rotor class
- The constructor and the other functions are public, so the other files can use them, and it uses Rotor public functions in itself