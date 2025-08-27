/************************************************************
 * File:         UnionIntersectionOfaay.cpp
 * Author:       Deepesh Soni
 * Created on:   2025-08-06
 * Description:  Given an integer array arr[], find the subarray (containing at least one element) which has the maximum possible sum.
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

// BruteForce O(n2)
int MaximumSumBrute(const vector<int> &arr)
{
    int maxSum = arr[0];
    int lastRes = 0;
    pair<int, int> range;
    for (int i = 0; i < arr.size(); i++)
    {
        int currSum = 0;
        for (int j = i; j < arr.size(); j++)
        {
            currSum += arr[j];
            if (currSum > maxSum)
            {
                maxSum = currSum;
                range.first = i;
                range.second = j;
            }
        }
    }

    cout << range.first << ":" << range.second << "\n";
    return maxSum;
}

// Kadane's algorithm O(n)
int MaximumSumKadane(const vector<int> &arr)
{
    int maxSum = arr[0];
    int currSum = arr[0];
    int tempStart = 0;
    pair<int, int> range{0, 0};

    for (int i = 1; i < arr.size(); ++i)
    {
        if (arr[i] > currSum + arr[i])
        {
            currSum = arr[i];
            tempStart = i;
        }
        else
        {
            currSum += arr[i];
        }
        if (currSum > maxSum)
        {
            maxSum = currSum;
            range.first = tempStart;
            range.second = i;
        }
    }

    cout << range.first << ":" << range.second << "\n";
    return maxSum;
}

int main()
{
    vector<int> arr{2, -2, 0, -8, 11, 1, 2};
    cout << MaximumSumBrute(arr);
    cout << "\n";
    cout << MaximumSumKadane(arr);
    return 0;
}