#include <string>

class Player
{
private:
    std::string name;
public:
    virtual char makeMove() = 0;
    void setName(std::string name);
    std::string getName();
};
