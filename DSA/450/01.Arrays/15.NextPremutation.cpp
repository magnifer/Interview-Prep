/************************************************************
 * Author:            Deepesh Soni
 * Description:       Given an array of intervals where intervals[i] = [starti, endi], merge all overlapping intervals,
 *                    and return an array of the non-overlapping intervals that cover all the intervals in the input.
 * Problem Link:      https://leetcode.com/problems/merge-intervals/description/
 * Time Complexity:   O(n)
 * Space Complexity:  O(1)
 *
 * Compiler:          MSVC 19.41, C++20
 * Build:             cl /std:c++17 /EHsc MaxAndMinElementInaay.cpp
 *
 * License:           MIT License (or specify your license)
 ************************************************************/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> merge(vector<vector<int>> &intervals)
{
    sort(intervals.begin(), intervals.end(),
         [](const vector<int> &a, const vector<int> &b)
         {
             return a[0] < b[0];
         });

    vector<vector<int>> res;
    res.push_back(intervals[0]);

    for (int i = 1; i < intervals.size(); ++i)
    {
        if (res.back()[1] >= intervals[i][0])
        {
            res.back()[1] = max(res.back()[1], intervals[i][1]);
        }
        else
        {
            res.push_back(intervals[i]);
        }
    }
    return res;
}

int main()
{
    vector<vector<int>> nums{{1, 3}, {2, 6}, {8, 10}, {15, 18}};

    vector<vector<int>> res = merge(nums);
    for (auto vec : res)
    {
        cout << "[" << vec[0] << "," << vec[1] << "],";
    }

    return 0;
}