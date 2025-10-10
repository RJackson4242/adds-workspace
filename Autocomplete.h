#include <string>
#include <vector>
#include "Node.h"

using namespace std;

class Autocomplete
{
private:
    Node *head;
    void findChildren(Node *node, vector<string> &accumulator);
    void deleteBranch(Node *node);

public:
    Autocomplete();
    ~Autocomplete();
    vector<string> getSuggestions(string partialWord); // return the known words that start with partialWord
    void insert(string word);                          // add a word to the known words
};