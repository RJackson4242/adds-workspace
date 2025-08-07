#pragma once
#include "Move.h"
#include "MoveFactory.h"
#include <string>

class Player
{
private:
    std::string name;

protected:
    Player(std::string name);

public:
    virtual Move *makeMove() = 0;
    std::string getName();
};
