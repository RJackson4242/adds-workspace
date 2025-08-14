#include <string>
using namespace std;

class Reverser
{
public:
    int reverseDigit(int value);
    string reverseString(string characters);

private:
    int reverseDigit(int value, int acc);
    string reverseString(string characters, string acc);
};