/*
 * @author Deepesh Soni
 * Problem: Find if strings are anagram
 * Time Complexity: O(n)
 * Space Complexity: O(n)
 */

#include <iostream>
#include <unordered_map>
using namespace std;

bool IsAnagram(string s, string t)
{
	if (s.length() != t.length())
		return false;

	unordered_map<char, int> map;

	for (int i = 0; i < s.length(); i++)
	{
		if (map.find(s[i]) == map.end())
			map[s[i]] = 1;
		else
			++map[s[i]];
	}
	for (int i = 0; i < s.length(); i++)
	{
		if (map.find(t[i]) != map.end())
		{
			--map[t[i]];
		}
		else
			return false; // return here since char doesnt exist
	}
	for (auto c : s)
	{
		if (map[c] != 0)
			return false;
	}
	return true;
}

int main()
{
	string input = "anagram";
	string input1 = "gaaanrm";
	IsAnagram(input, input1);

	return 0;
}