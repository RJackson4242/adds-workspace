#include "bigNumCalc.h"
#include <algorithm>

std::list<int> bigNumCalc::buildBigNum(std::string numString)
{
    std::list<int> result;
    for (char c : numString)
    {
        result.push_back(c - '0');
    }
    return result;
}

std::list<int> bigNumCalc::add(std::list<int> num1, std::list<int> num2)
{
    std::list<int> result;
    auto it1 = num1.rbegin();
    auto it2 = num2.rbegin();
    int carry = 0;

    while (it1 != num1.rend() || it2 != num2.rend() || carry > 0)
    {
        int d1 = (it1 != num1.rend()) ? *it1++ : 0;
        int d2 = (it2 != num2.rend()) ? *it2++ : 0;

        int sum = d1 + d2 + carry;
        result.push_front(sum % 10);
        carry = sum / 10;
    }

    return result;
}

std::list<int> bigNumCalc::sub(std::list<int> num1, std::list<int> num2)
{
    std::list<int> result;
    auto it1 = num1.rbegin();
    auto it2 = num2.rbegin();
    int borrow = 0;

    while (it1 != num1.rend())
    {
        int d1 = *it1 - borrow;
        int d2 = (it2 != num2.rend()) ? *it2 : 0;

        if (d1 < d2)
        {
            d1 += 10;
            borrow = 1;
        }
        else
        {
            borrow = 0;
        }

        result.push_front(d1 - d2);

        ++it1;
        if (it2 != num2.rend())
            ++it2;
    }

    while (!result.empty() && result.front() == 0)
        result.pop_front();

    if (result.empty())
        result.push_back(0);

    return result;
}

std::list<int> bigNumCalc::mul(std::list<int> num1, std::list<int> num2)
{
    if (num1.front() == 0) return {0};
    if (num2.front() == 0) return {0};

    std::list<int> result = {0};
    int zeros = 0;

    for (auto it2 = num2.rbegin(); it2 != num2.rend(); ++it2)
    {
        std::list<int> temp;
        int carry = 0;

        for (int i = 0; i < zeros; ++i)
            temp.push_back(0);

        for (auto it1 = num1.rbegin(); it1 != num1.rend(); ++it1)
        {
            int mul = (*it1) * (*it2) + carry;
            temp.push_front(mul % 10);
            carry = mul / 10;
        }

        if (carry > 0)
            temp.push_front(carry);

        result = add(result, temp);
        zeros++;
    }

    return result;
}


