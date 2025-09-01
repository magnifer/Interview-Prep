/************************************************************
 * File:        MergeSort.cpp
 * Author:      Deepesh Soni
 * Created on:  2025-08-06
 * Description: Merge Sort Techique
 ************************************************************/

#include <iostream>
#include <vector>
using namespace std;

// Merge two sorted subarrays into one sorted array
void Merge(vector<int> &nums, int left, int mid, int right)
{
    int n1 = mid - left + 1; // size of left subarray
    int n2 = right - mid;    // size of right subarray

    // temporary arrays
    vector<int> L(n1), R(n2);

    // copy data to temp array L[] & R[]
    for (int i = 0; i < n1; ++i)
    {
        L[i] = nums[left + i];
    }
    for (int j = 0; j < n2; ++j)
    {
        R[j] = nums[mid + 1 + j];
    }

    // Merge the temp arrays back into nums[left...right]
    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
            nums[k++] = L[i++];
        else
            nums[k++] = R[j++];
    }

    // Copy remaining elements of L[]
    while (i < n1)
        nums[k++] = L[i++];

    // Copy remaining elements of R[]
    while (j < n2)
        nums[k++] = R[j++];
}

void MergeSort(vector<int> &nums, int left, int right)
{
    if (left < right)
    {
        int mid = left + (right - left) / 2;

        MergeSort(nums, left, mid);
        MergeSort(nums, mid + 1, right);

        Merge(nums, left, mid, right);
    }
}
int main()
{
    vector<int> nums{2, 8, 3, 7, 9, 48, 5, 11, 6};
    MergeSort(nums, 0, nums.size() - 1);

    for (auto num : nums)
    {
        cout << num << " ";
    }
    return 0;
}