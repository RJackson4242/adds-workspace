#include "BubbleSort.h"
#include <algorithm>

std::vector<int> BubbleSort::sort(std::vector<int> list)
{
    int size = list.size();
    if (size <= 1)
    {
        return list;
    }
    for (int i = 0; i < size; i++)
    {
        for (int j = 1; j < size - i; j++)
        {
            if (list.at(j) < list.at(j + 1))
            {
                std::iter_swap(list.begin() + i, list.begin() + j);
            }
        }
    }
    return list;
}