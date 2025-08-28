#include "Finder.h"

using namespace std;

vector<int> Finder::findSubstrings(string s1, string s2) {

    vector<int> result(s2.size(), -1);
    size_t start = 0;
    string substring;

    for(size_t i = 1; i <= s2.size(); i++) {
        substring.push_back(s2[i-1]);
        size_t found = s1.find(substring, start);
        if (found != string::npos) {
            result[i-1], start = (found);
        } else {
            return result;
        }
    }
    return result;
}
