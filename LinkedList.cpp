#include "LinkedList.h"
#include <iostream>
#include <limits>

LinkedList::LinkedList() : head(nullptr) {}

LinkedList::LinkedList(int *array, int len)
{
    if (len <= 0)
    {
        head = nullptr;
        return;
    }
    head = new Node;
    head->data = array[0];
    Node *currentNode = head;
    for (int i = 1; i < len; i++)
    {
        currentNode = currentNode->link = new Node;
        currentNode->data = array[i];
    }
}

LinkedList::~LinkedList()
{
    Node *currentNode = head;
    while (currentNode != nullptr)
    {
        Node *next = currentNode->link;
        delete currentNode;
        currentNode = next;
    }
}

void LinkedList::insertPosition(int pos, int newNum)
{
    Node *newNode = new Node;
    newNode->data = newNum;
    if (pos <= 1 || head == nullptr)
    {
        newNode->link = head;
        head = newNode;
        return;
    }
    Node *currentNode = head;
    for (int i = 2; i < pos && currentNode->link != nullptr; i++)
    {
        currentNode = currentNode->link;
    }
    newNode->link = currentNode->link;
    currentNode->link = newNode;
}

bool LinkedList::deletePosition(int pos)
{
    if (head == nullptr)
    {
        return false;
    }
    Node *currentNode = head;
    if (pos == 1)
    {
        head = head->link;
        delete currentNode;
        return true;
    }
    for (int i = 2; i < pos; i++)
    {
        if (currentNode->link == nullptr)
        {
            return false;
        }
        currentNode = currentNode->link;
    }
    if (currentNode->link == nullptr)
    {
        return false;
    }
    Node *next = currentNode->link->link;
    delete currentNode->link;
    currentNode->link = next;
    return true;
}

int LinkedList::get(int pos)
{
    if (head == nullptr || pos <= 0)
    {
        return std::numeric_limits<int>::max();
    }
    Node *currentNode = head;
    for (int i = 1; i < pos; i++)
    {
        if (currentNode->link == nullptr)
        {
            return std::numeric_limits<int>::max();
        }
        currentNode = currentNode->link;
    }
    return currentNode->data;
}

int LinkedList::search(int target)
{
    Node *currentNode = head;
    int index = 1;
    while (currentNode != nullptr)
    {
        if (currentNode->data == target)
        {
            return index;
        }
        currentNode = currentNode->link;
        index++;
    }
    return -1;
}

void LinkedList::printList()
{
    if (head == nullptr)
    {
        return;
    }
    Node *currentNode = head;
    std::cout << '[';
    while (currentNode->link != nullptr)
    {
        std::cout << currentNode->data << ' ';
        currentNode = currentNode->link;
    }
    std::cout << currentNode->data << ']';
}
