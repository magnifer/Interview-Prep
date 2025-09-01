/************************************************************
 * Author:            Deepesh Soni
 * Description:       Given an integer array arr[] of size n, find the inversion count in the array.
 *                    Two array elements arr[i] and arr[j] form an inversion if arr[i] > arr[j] and i < j.
 * Problem Link:
 * Time Complexity:   O(nlogn)
 * Space Complexity:
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

int InversionCountBrute(vector<int> &nums)
{
    int count = 0;
    int n = nums.size();

    for (int i = 0; i < n - 1; ++i)
    {
        for (int j = i + 1; j < n; ++j)
        {
            if (nums[i] > nums[j])
            {
                count++;
            }
        }
    }

    return count;
}

int Merge(vector<int> &nums, int left, int mid, int right)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;

    vector<int> L(n1), R(n2);
    for (int i = 0; i < n1; i++)
    {
        L[i] = nums[i + 1];
    }
    for (int j = 0; j < n2; j++)
    {
        R[j] = nums[mid + 1 + j];
    }

    int res = 0;
    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            nums[k++] = L[i++];
        }
        else
        {
            nums[k++] = R[j++];
            res += (n1 - i);
        }
    }

    while (i < n1)
    {
        nums[k++] = L[i++];
    }
    while (j < n2)
    {
        nums[k++] = R[j++];
    }

    return res;
}

int InversionCount(vector<int> &nums, int left, int right)
{
    // Merge Sort
    int res = 0;

    if (left < right)
    {
        int mid = left + (right - left) / 2;
        res += InversionCount(nums, left, mid);
        res += InversionCount(nums, mid + 1, right);

        res += Merge(nums, left, mid, right);
    }

    return res;
}

int main()
{
    vector<int> nums{4, 3, 5, 7, 2, 1};
    cout << InversionCount(nums, 0, nums.size() - 1);

    return 0;
}