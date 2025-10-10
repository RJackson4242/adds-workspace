#include "Node.h"

class PrefixMatcher
{
private:
    Node *head;
    void deleteBranch(Node *node);
public:
    PrefixMatcher();
    ~PrefixMatcher();
    int selectRouter(string networkAddress);  // return the router with the longest matching prefix
    void insert(string address, int routerNumber); // add a router address
};
