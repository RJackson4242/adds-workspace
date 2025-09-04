#include "RecursiveBinarySearch.h"

bool RecursiveBinarySearch::search(std::vector<int> list, int num)
{
    return search(list, num, 0, list.size() - 1);
}

bool RecursiveBinarySearch::search(std::vector<int> list, int num, int start, int end)
{
    if (start <= end)
    {
        int mid = start + (end - start) / 2;
        if (list.at(mid) == num)
        {
            return true;
        }
        if (list.at(mid) < num)
        {
            return search(list, num, mid + 1, end);
        }
        return search(list, num, start, mid - 1);
    }
    return false;
}