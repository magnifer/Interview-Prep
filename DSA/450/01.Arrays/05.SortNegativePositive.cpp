/************************************************************
 * File:         ReverseTheArray.cpp
 * Author:       Deepesh Soni
 * Created on:   2025-08-06
 * Description:  Given an array which consists of only negative & positive. Sort the array without using any sorting algo
 * Problem Link:
 *
 * Compiler:     MSVC 19.41, C++17
 * Build:        cl /std:c++17 /EHsc MaxAndMinElementInArray.cpp
 *
 * License:      MIT License (or specify your license)
 ************************************************************/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> Sort(vector<int> &arr)
{
    int n = arr.size();
    int start = 0;
    int end = n - 1;

    while (start <= end)
    {
        if (arr[start] < 0)
        {
            start++;
        }
        else
        {
            std::swap(arr[start], arr[end]);
            end--;
        }
    }

    return arr;
}

int main()
{
    vector<int> arr{0, -1, 7, -1, -1, 0, 6, 2, 3, 4, 2};
    Sort(arr);
    for (auto element : arr)
        cout << element << " ";

    return 0;
}