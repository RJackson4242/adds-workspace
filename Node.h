#pragma once

class Node
{
    friend class LinkedList;

private:
    int data;
    Node *link;

public:
    Node();
};
