/************************************************************
 * File:         UnionIntersectionOfaay.cpp
 * Author:       Deepesh Soni
 * Created on:   2025-08-06
 * Description:  Merge 2 sorted arrays in nums1 without extra space & in O(m+n)
 * Problem Link: https://leetcode.com/problems/merge-sorted-array/description/
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

void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
{
    // after m elements, all elements are 0 in nums1 0, so start from end.
    int i = m - 1, j = n - 1, k = m + n - 1;

    while (j >= 0)
    {
        if (i >= 0 && nums1[i] > nums2[j])
        {
            nums1[k] = nums1[i];
            i--;
        }
        else
        {
            nums1[k] = nums2[j];
            j--;
        }
        k--;
    }
}

int main()
{

    vector<int> nums1{1, 3, 5, 8, 10, 0, 0, 0, 0};
    vector<int> nums2{2, 6, 7, 9};

    int m = 5; // number of initialized elements in nums1
    int n = nums2.size();

    merge(nums1, m, nums2, n);
    for (auto element : nums1)
        cout << element << " ";

    return 0;
}