#include "DocumentManager.h"

void DocumentManager::addDocument(string name, int id, int license_limit)
{
    Document doc = {id, name, license_limit};
    documentsByID[id] = doc;
    nameToID[name] = id;
    borrowed[id] = unordered_set<int>();
}

void DocumentManager::addPatron(int patronID)
{
    patrons.insert(patronID);
}

int DocumentManager::search(string name)
{
    int id = nameToID[name];
    if (id) { return id; } else { return 0; }
}

bool DocumentManager::borrowDocument(int docid, int patronID)
{
    if (!patrons.count(patronID)) { return false; }
    if (!documentsByID.count(docid)) { return false; }
    unordered_set<int> borrowers = borrowed[docid];
    if(borrowers.count(patronID)) { return false; }
    int max = documentsByID[docid].license_limit;
    if (borrowers.size() >= max) { return false; }
    borrowers.insert(patronID);
    return true;
}

void DocumentManager::returnDocument(int docid, int patronID)
{
    if (!documentsByID.count(docid)) { return; }
    borrowed[docid].erase(patronID);
}
