#include "Move.h"

class MoveFactory
{
public:
    static Move *getMove(std::string moveName);
};