#include "QuickSort.h"
#include <algorithm>

std::vector<int> QuickSort::sort(std::vector<int> list)
{
    if (list.size() <= 1)
    {
        return list;
    }

    int pivotIndex = (list.size() >= 3) ? 2 : (list.size() - 1);
    int pivot = list[pivotIndex];

    std::vector<int> left;
    std::vector<int> right;

    for (int i = 0; i < list.size(); i++)
    {
        if (i==(pivotIndex)) {continue;}
        if (list.at(i) < pivot)
        {
            left.push_back(list.at(i));
        }
        else
        {
            right.push_back(list.at(i));
        }
    }

    left = sort(left);
    left.push_back(pivot);
    right = sort(right);
    left.insert(left.end(), right.begin(), right.end());

    return left;
}