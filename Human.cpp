#include "Human.h"
#include <iostream>

Human::Human() {
    setName("Human");
}

Human::Human(std::string name) {
    setName(name);
}

char Human::makeMove() {
    std::cout << "Enter move: ";
    char move;
    std::cin >> move;
    return move;
}