#pragma once
#include <string>
#include <unordered_map>
#include <unordered_set>
using std::string, std::unordered_map, std::unordered_set;

class DocumentManager
{
private:
    // Document data
    struct Document
    {
        int id;
        std::string name;
        int license_limit;
    };

    unordered_map<int, Document> documentsByID;           // docid -> Document
    unordered_map<std::string, int> nameToID;             // name -> docid
    unordered_set<int> patrons;                           // patronID
    unordered_map<int, std::unordered_set<int>> borrowed; // docid -> set of patronIDs
public:
    void addDocument(string name, int id, int license_limit);

    void addPatron(int patronID);

    int search(string name); // returns docid if name is in the document collection or 0 if the name is not in the collection

    bool borrowDocument(int docid, int patronID); // returns true if document is borrowed, false if it can not be borrowed (invalid patronid or the number of copies current borrowed has reached the license limit)

    void returnDocument(int docid, int patronID);
};
