#pragma once
#include "Player.h"

class Human: public Player
{
private:
public:
    Human();
    Human(std::string name);
    char makeMove();
};