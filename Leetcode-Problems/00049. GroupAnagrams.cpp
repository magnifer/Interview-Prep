/*
 * @author Deepesh Soni
 * Problem: Given an array of strings strs, group the anagrams together
 * Time Complexity: O(m*nlogn)
 * Space Complexity: O()
 */

#include <bits/stdc++.h>
using namespace std;

vector<vector<string>> groupAnagrams(vector<string> &strs)
{
	// create a map which will store all string of same length together
	// check if there are anagrams for each key
	//
	unordered_map<string, vector<string>> map;

	for (auto str : strs)
	{
		auto input = str;
		sort(input.begin(), input.end());
		map[input].push_back(str);
	}

	vector<vector<string>> result;
	for (auto element : map)
	{
		result.push_back(element.second);
	}

	return result;
}

int main()
{
	vector<string> s{"eat", "tea", "tan", "ate", "nat", "bat", "abcd"};

	const auto res = groupAnagrams(s);
	for (auto vec : res)
	{
		for (auto str : vec)
			cout << str << " ";
		cout << "\n";
	}

	return 0;
}