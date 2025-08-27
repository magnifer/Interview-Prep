/************************************************************
 * File:         UnionIntersectionOfaay.cpp
 * Author:       Deepesh Soni
 * Created on:   2025-08-06
 * Description:  Minimum number of jumps to reach end.
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

int MinimumJumps(const vector<int> &arr)
{
    if (arr[0] == 0)
        return -1;

    int jump = 0;
    int maxReach = 0;
    int currReach = 0;
    int n = arr.size();
    for (int i = 0; i < n; i++)
    {
        maxReach = max(maxReach, i + arr[i]);

        if (maxReach >= n - 1)
        {
            return jump + 1;
        }
        if (i == currReach)
        {
            if (i == maxReach)
                return -1;
            else
            {
                jump++;
                currReach = maxReach;
            }
        }
    }

    return -1;
}

int main()
{
    vector<int> arr{1, 3, 5, 8, 9, 2, 6, 7, 6, 8, 9};
    cout << MinimumJumps(arr);
    return 0;
}