/*
 * @author Deepesh Soni
 * Problem: Single Number
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */

#include <bits/stdc++.h>
using namespace std;

int singleNumber(vector<int> &nums)
{
	int res = 0;
	for (auto num : nums)
		res = res ^ num;

	return res;
}

int main()
{
	vector<int> v = {4, 1, 2, 1, 2, 4, 3};
	cout << singleNumber(v);
	return 0;
}