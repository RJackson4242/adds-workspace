#include "Computer.h"

Computer::Computer() : Player("Computer") {}

Move *Computer::makeMove()
{
    return MoveFactory::getMove("Rock");
}