/************************************************************
 * File:         UnionIntersectionOfaay.cpp
 * Author:       Deepesh Soni
 * Created on:   2025-08-06
 * Description:  find duplicate in an array of N+1 Integers,
 *               without modifying the array nums and using only constant extra space.
 * Problem Link: https://leetcode.com/problems/find-the-duplicate-number/description/
 *
 * Compiler:     MSVC 19.41, C++17
 * Build:        cl /std:c++17 /EHsc MaxAndMinElementInaay.cpp
 *
 * License:      MIT License (or specify your license)
 ************************************************************/

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>

using namespace std;

/*
 * Solved using set
 * space complexity: O(n), time complexity O(n)
 */
int FindDuplicateUsingSet(vector<int> &nums)
{
    unordered_set<int> seen;
    for (auto num : nums)
    {
        if (seen.contains(num))
            return num;
        seen.insert(num);
    }
    return 0;
}

int FindDuplicate(const vector<int> &nums)
{
    int slow = nums[0];
    int fast = nums[0];

    do
    {
        slow = nums[slow];
        fast = nums[nums[fast]];
    } while (slow != fast);

    fast = nums[0];
    while (slow != fast)
    {
        slow = nums[slow];
        fast = nums[fast];
    }

    return slow;
}

int main()
{
    vector<int> arr{1, 3, 5, 8, 9, 2, 6, 7, 6};
    cout << FindDuplicateUsingSet(arr) << "\n";
    cout << FindDuplicate(arr);
    return 0;
}