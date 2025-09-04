#include <iostream>
#include <vector>
#include <sstream> // only for splitting input line
#include "QuickSort.h"
#include "RecursiveBinarySearch.h"

int main()
{
    std::string line;
    std::getline(std::cin, line);

    std::vector<int> list;
    std::stringstream ss(line);
    int value;

    while (ss >> value)
    {
        list.push_back(value);
    }

    QuickSort sorter = QuickSort();
    list = sorter.sort(list);

    bool search = RecursiveBinarySearch::search(list, 1);

    std::cout << (search ? "true" : "false");

    for (int num : list)
    {
        std::cout << " " << num;
    }
    std::cout << std::endl;

    return 0;
}
