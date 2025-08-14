#include "Reverser.h"

int Reverser::reverseDigit(int value)
{
    return reverseDigit(value, 0);
}

int Reverser::reverseDigit(int value, int acc)
{
    if (value == 0) { return acc; }
    return reverseDigit(value / 10, acc * 10 + value % 10);
}

string Reverser::reverseString(string characters)
{
    return reverseString(characters, "");
}

string Reverser::reverseString(string characters, string acc)
{
    if (characters.length() == 0) { return acc; }
    acc += characters.back();
    characters.pop_back();
    return reverseString(characters, acc);
}