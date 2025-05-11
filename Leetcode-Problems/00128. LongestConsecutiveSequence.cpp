/*
 * @author Deepesh Soni
 * Problem: 347. Longest Consecutive subsequence
 * Given an integer array nums find longest consecutive subsequence.
 * Approach:
 * 		Step 1: use a set to add elements.
 * 		Step 2: loop over array length. if element x is first element then x-1 doesn't exixt in array.
 * 		Step 3:	check if x+1, x+2, x+...i exist in array, x+i-x will be the max length for this iteration.
 * 		Step 4: calculate max( max, x+i-x);
 *
 * Time Complexity: O(n)
 * Space Complexity: O(n)
 */

#include <bits/stdc++.h>
using namespace std;

int longestConsecutive(vector<int> &nums)
{
	unordered_set<int> mset;
	for (const int n : nums)
	{
		mset.insert(n);
	}

	int res = 0;

	for (const auto n : nums)
	{
		if (!mset.count(n - 1))
		{
			int j = n + 1;

			while (mset.count(j))
			{
				j++;
			}
			res = max(res, j - n);
		}
	}

	return res;
}

int main()
{
	vector<int> v{100, 4, 200, 1, 3, 2};
	cout << longestConsecutive(v);

	return 0;
}