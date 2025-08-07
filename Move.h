#pragma once
#include <string>
#include <vector>

class Move
{
protected:
    std::string name;
    std::vector<std::string> winsAgainst;

public:
    Move(std::string name, std::vector<std::string> winsAgainst);
    bool beatsMove(Move *move);
    std::string getName();
};