/************************************************************
 * File:         KthSmallestElementInArray.cpp
 * Author:       Deepesh Soni
 * Created on:   2025-08-06
 * Description:  Finds the Kth smallest element in an array
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

int KthSmallestElement(vector<int> &arr, int &k)
{
    int n = arr.size();

    for (int i = 0; i < n; ++i)
    {
        sort(arr.begin(), arr.end());
    }

    return arr[k - 1];
}

int main()
{
    vector<int> arr{-1, 2, -3, 4, 5, 6};
    int k = 2;
    cout << KthSmallestElement(arr, k);

    return 0;
}