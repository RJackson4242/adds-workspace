#include <map>
#include <string>
using namespace std;

class Node
{
private:
    string value;
    bool isWord;
    map<char, Node*> children;
public:
    Node();
    friend class Autocomplete;
    friend class PrefixMatcher;
};
