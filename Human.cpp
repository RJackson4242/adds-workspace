#include "Human.h"
#include <iostream>
#include "MoveFactory.h"

Human::Human() : Player("Human") {}

Human::Human(std::string name) : Player(name) {}

Move *Human::makeMove()
{
    std::cout << "Enter move: ";
    std::string move;
    std::cin >> move;
    return MoveFactory::getMove(move);
}