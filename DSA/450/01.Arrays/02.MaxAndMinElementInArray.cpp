/************************************************************
 * File:        MaxAndMinElementInArray.cpp
 * Author:      Deepesh Soni
 * Created on:  2025-08-06
 * Description: Finds the maximum and minimum elements in an array
 *
 * Compiler:    MSVC 19.41, C++17
 * Build:       cl /std:c++17 /EHsc MaxAndMinElementInArray.cpp
 *
 * License:     MIT License (or specify your license)
 ************************************************************/

#include <iostream>
#include <limits.h>
#include <vector>
using namespace std;

std::pair<int, int> MaxAndMinElement(vector<int> &arr)
{
    int n = arr.size();
    int min = INT_MAX;
    int max = INT_MIN;
    for (int i = 0; i < n; ++i)
    {
        if (arr[i] > max)
            max = arr[i];
        if (arr[i] < min)
            min = arr[i];
    }

    return std::make_pair(max, min);
}

int main()
{
    vector<int> arr{-1, 2, -3, 4, 5, 6};
    auto [a, b] = MaxAndMinElement(arr);
    std::cout << "Max: " << a << " Min: " << b << std::endl;

    return 0;
}