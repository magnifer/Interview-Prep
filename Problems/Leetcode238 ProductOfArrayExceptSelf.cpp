/*
 * @author Deepesh Soni
 * Problem: 347. Product of array except self element
 * Given an integer array nums, return an array answer such that answer[i] is equal to the product of all the elements of nums except nums[i].
 * Intuition:
 * 		if zero count is more than 1 then all the elements will be 0
 * 		if zero count is 1 all element will be 0 except element at 0th index
 * 		if zero count is 0 muliplication of all element / self element
 *
 * Time Complexity: O(n)
 * Space Complexity: O(n)
 */

#include <bits/stdc++.h>
using namespace std;

vector<int> productExceptSelf(vector<int> &nums)
{

	int zeroes = 0;

	int mul = 1;
	for (int i = 0; i < nums.size(); i++)
	{
		(nums[i] == 0) ? ++zeroes : mul *= nums[i];
	}

	vector<int> res(nums.size(), 0);
	if (zeroes > 1)
	{
		return res;
	}

	for (int i = 0; i < nums.size(); i++)
	{
		res[i] = (zeroes == 0) ? (mul / nums[i]) : (nums[i] == 0) ? mul
																  : 0;
	}
	return res;
}

int main()
{
	vector<int> v{1, 2, 3, 4};
	const auto res = productExceptSelf(v);

	cout << "result \n";
	for (const auto element : res)
		cout << element << " ";

	return 0;
}