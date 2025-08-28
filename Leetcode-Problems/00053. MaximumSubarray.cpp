/*
 * @author Deepesh Soni
 * Problem: Find if strings sre Palindrome using two pointer approach

 */

/************************************************************
 * Author:            Deepesh Soni
 * Description:       Given an integer array nums, find the subarray with the largest sum, and return its sum.
 * Problem Link:      https://leetcode.com/problems/maximum-subarray/description/
 * Time Complexity:   O(n)
 * Space Complexity:  O(1)
 *
 * Compiler:          MSVC 19.41, C++20
 * Build:             cl /std:c++17 /EHsc MaxAndMinElementInaay.cpp
 *
 * License:           MIT License (or specify your license)
 ************************************************************/

#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int maxSubArray(vector<int> &nums)
{

    if (nums.size() == 1)
        return nums[0];
    int n = nums.size();
    int currSum = nums[0];
    int maxSum = nums[0];

    for (int i = 1; i < n; i++)
    {
        currSum = max(nums[i], nums[i] + currSum);
        maxSum = max(currSum, maxSum);
    }

    return maxSum;
}
/* Find index as well
    int maxSubArray(vector<int>& nums) {
    if (nums.size() == 1)
        return nums[0];
    int n = nums.size();
    int currSum = nums[0];
    int maxSum = nums[0];
    int tempStart = 0;
    pair<int, int> range{0, 0};

    for (int i = 1; i < n; i++) {
        // Decide whether to start a new subarray or extend the current one
        if (nums[i] > (currSum + nums[i])) {
            tempStart = i;
            currSum = nums[i];
        } else {
            currSum += nums[i];
        }

        // Update max sum and indexes a better sum is found
        if (currSum > maxSum) {
            maxSum = currSum;
            range = {tempStart, i};
        }
    }

    return maxSum;
}
*/

int main()
{
    vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    cout << maxSubArray(nums) << "\n";

    return 0;
}