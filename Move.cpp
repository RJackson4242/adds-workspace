#include "Move.h"

Move::Move(std::string name, std::vector<std::string> winsAgainst) : name(name), winsAgainst(winsAgainst) {}

bool Move::beatsMove(Move *otherMove)
{
    for (std::string move : winsAgainst)
    {
        if (otherMove->getName() == move)
        {
            return true;
        }
    }
    return false;
};