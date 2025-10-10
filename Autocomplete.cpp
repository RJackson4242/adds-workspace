#include "Autocomplete.h"

Autocomplete::Autocomplete() { head = new Node(); }

Autocomplete::~Autocomplete()
{
    deleteBranch(head);
}

void Autocomplete::deleteBranch(Node *node)
{
    for (auto childNode : node->children){
        deleteBranch(childNode.second);
    }
    delete node;
}

vector<string> Autocomplete::getSuggestions(string partialWord)
{
    Node *currentNode = head;
    vector<string> suggestions;
    for (char character : partialWord)
    {
        if (!currentNode->children.count(character)) {
            return suggestions;
        }
        currentNode = currentNode->children.at(character);
    }
    findChildren(currentNode, suggestions);
    return suggestions;
}

void Autocomplete::findChildren(Node *node, vector<string> &accumulator)
{
    if (node->isWord) {
        accumulator.push_back(node->value);
    }
    for (auto childNode : node->children){
        findChildren(childNode.second, accumulator);
    }
}

void Autocomplete::insert(string word)
{
    Node *currentNode = head;
    for (char character : word)
    {
        if (!currentNode->children.count(character)) {
            currentNode->children.insert({character, new Node()});
        }
        currentNode = currentNode->children.at(character);
    }
    currentNode->isWord = true;
    currentNode->value = word;
}
