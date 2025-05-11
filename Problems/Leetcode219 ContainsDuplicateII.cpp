/*
 * @author Deepesh Soni
 * Problem: Find if duplicate element exist
 * Time Complexity: O(n)
 * Space Complexity: O(n)
 */

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

bool containsNearbyDuplicate(vector<int> &nums, int k)
{
	unordered_map<int, int> map;
	for (int i = 0; i < nums.size(); i++)
	{
		int num = nums[i];
		if (map.find(num) != map.end() && i - map[num] <= k)
			return true;
		else
			map[num] = i;
	}
	return false;
}

int main()
{
	vector<int> nums{1, 2, 3, 1};
	cout << ContainsDuplicate(nums);

	return 0;
}