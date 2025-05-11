/*
 * @author Deepesh Soni
 * Problem: 347. TopK Frequent elements
 * Given an integer array nums and an integer k, return the k most frequent elements.
 * Approach:
 * 		Step 1: use a map to get the frequency count.
 * 		Step 2: use bucket sort of length array size + 1 & values will be list of numbers that appeared with that specific frequency.
 *				eg if nums{1,1,1,2,2,2,3} bucket will be of size 7 bucket{{},{3},{},{1,2},{},{},{},{}}
				top 2 elements will be {1,2}
 * 		Step 3: search throuch this bucket from end to start & return top k.
 *
 * Time Complexity: O(n)
 * Space Complexity: O(n)
 */

#include <bits/stdc++.h>
using namespace std;

vector<int> topKFrequent(vector<int> &nums, int k)
{
	map<int, int> umap;

	for (auto num : nums)
	{
		++umap[num];
	}

	for (auto element : umap)
	{
		cout << element.first << " " << element.second << "\n";
	}

	cout << "bucket\n";
	vector<vector<int>> bucket;
	bucket.resize(nums.size() + 1);
	for (auto m : umap)
	{
		bucket[m.second].push_back(m.first);
	}
	for (int i = 0; i < nums.size(); i++)
	{
		cout << "index " << i << ": ";
		for (auto element : bucket[i])
		{
			cout << element << " ";
		}
		cout << "\n";
	}
	vector<int> res;
	for (int i = nums.size(); i > 0; i--)
	{
		for (int j = 0; j < bucket[i].size(); j++)
		{
			res.emplace_back(bucket[i].at(j));
			if ((res.size() == k))
				return res;
		}
	}
	return res;
}

int main()
{
	vector<int> v{1, 1, 1, 2, 2, 2, 3, 3, 4};
	int k = 2;
	const auto res = topKFrequent(v, k);

	cout << "result \n";
	for (const auto element : res)
		cout << element << " ";

	return 0;
}