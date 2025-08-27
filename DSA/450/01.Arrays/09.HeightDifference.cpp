/************************************************************
 * File:         UnionIntersectionOfaay.cpp
 * Author:       Deepesh Soni
 * Created on:   2025-08-06
 * Description:  Given the heights of n towers and a positive integer k, increase or decrease the height of all towers by k (only once).
 *               After modifications, the task is to find the minimum difference between the heights of the tallest and the shortest tower.
 * Problem Link:
 *
 * Compiler:     MSVC 19.41, C++17
 * Build:        cl /std:c++17 /EHsc MaxAndMinElementInaay.cpp
 *
 * License:      MIT License (or specify your license)
 ************************************************************/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// BruteForce O(n)
int MaxDiff(vector<int> &arr)
{
    int res = 0;

    return res;
}

int main()
{
    vector<int> arr{2, -2, 0, -8, 11, 1, 2};
    cout << MaxDiff(arr);

    return 0;
}