#pragma once
#include <vector>
class RecursiveBinarySearch
{
public:
    static bool search(std::vector<int> list, int num);

private:
    static bool search(std::vector<int> list, int num, int start, int end);
};
