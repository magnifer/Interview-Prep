/*
 * @author Deepesh Soni
 * Problem: Find if duplicate element exist
 * Time Complexity: O(n)
 * Space Complexity: O(n)
 */

#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

bool ContainsDuplicate(vector<int> &nums)
{
	if (nums.size() == 0)
		return false;
	unordered_set<int> set;
	for (const int &i : nums)
	{
		if (set.count(i) > 0)
		{
			return true;
		}
		set.insert(i);
	}
	return false;
}

int main()
{
	vector<int> nums{1, 2, 3, 1};
	cout << ContainsDuplicate(nums);

	return 0;
}