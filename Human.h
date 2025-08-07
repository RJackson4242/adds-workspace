#pragma once
#include "Player.h"

class Human : public Player
{
private:
public:
    Human(std::string name);
    Human();
    Move *makeMove();
};