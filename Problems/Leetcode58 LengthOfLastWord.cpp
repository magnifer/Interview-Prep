/*
 * @author Deepesh Soni
 * Problem: 58. length of last word
 * Given an string, find length of last word
 * Time Complexity: O(n)
 * Space Complexity: O(n)
 */

#include <bits/stdc++.h>
using namespace std;

int lengthOfLastWord(string s)
{
	int len = 0;

	for (int i = s.length() - 1; i >= 0; i--)
	{
		if (s[i] != ' ')
			++len;
		if (s[i] == ' ' && len > 0)
			break;
	}
	return len;
}

int main()
{
	string s = "eat tea tan ate nat abvc";
	cout << lengthOfLastWord(s);

	return 0;
}