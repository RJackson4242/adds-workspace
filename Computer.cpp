#include "Computer.h"
#include "MoveFactory.h"

Computer::Computer() : Player("Computer") {}

Move *Computer::makeMove()
{
    return MoveFactory::getMove("Rock");
}