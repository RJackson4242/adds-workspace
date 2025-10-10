#include "PrefixMatcher.h"
#include <iostream>

PrefixMatcher::PrefixMatcher() : head(new Node())
{
}

PrefixMatcher::~PrefixMatcher()
{
    deleteBranch(head);
}

void PrefixMatcher::deleteBranch(Node *node)
{
    for (auto childNode : node->children)
    {
        deleteBranch(childNode.second);
    }
    delete node;
}

int PrefixMatcher::selectRouter(string networkAddress)
{
    Node *currentNode = head;
    int closestRouter = 0;
    for (char character : networkAddress)
    {
        if (currentNode->isWord)
        {
            closestRouter = stoi(currentNode->value);
        }
        if (!currentNode->children.count(character))
        {
            break;
        }
        currentNode = currentNode->children.at(character);
    }
    return closestRouter;
}

void PrefixMatcher::insert(string address, int routerNumber)
{
    Node *currentNode = head;
    for (char character : address)
    {
        if (!currentNode->children.count(character))
        {
            currentNode->children.insert({character, new Node()});
        }
        currentNode = currentNode->children.at(character);
    }
    currentNode->isWord = true;
    currentNode->value = to_string(routerNumber);
}