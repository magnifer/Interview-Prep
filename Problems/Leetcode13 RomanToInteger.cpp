/*
 * @author Deepesh Soni
 * Problem: Find integer value of RomanNumber
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */

#include <iostream>
#include <unordered_map>
using namespace std;

int romanToInt(string s)
{
	unordered_map<char, int> map;

	map['I'] = 1;
	map['V'] = 5;
	map['X'] = 10;
	map['L'] = 50;
	map['C'] = 100;
	map['D'] = 500;
	map['M'] = 1000;

	int ans = map[s[s.length() - 1]];
	for (int i = 0; i < s.length() - 1; i++)
	{
		ans = map[s[i]] < map[s[i + 1]] ? ans - map[s[i]] : ans + map[s[i]];
	}
	return ans;
}

int main()
{
	string input = "MCMXCIV";
	cout << romanToInt(input);

	return 0;
}