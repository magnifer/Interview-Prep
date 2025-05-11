/*
 * @author Deepesh Soni
 * Problem: Longest Common Prefix
 * Time Complexity: O(m*n*log(n))
 * Space Complexity: O(1)
 */

#include <bits/stdc++.h>
using namespace std;

string longestCommonPrefix(vector<string> &v)
{
	sort(v.begin(), v.end());

	string ans;
	for (int i = 0; i < v[0].length(); i++)
	{
		if (v[0].at(i) == v[v.size() - 1].at(i))
		{
			ans += v[0].at(i);
		}
		else
		{
			break;
		}
	}
	return ans;
}

int main()
{
	vector<string> strs = {"flower", "flow", "flight"};

	cout << longestCommonPrefix(strs);

	return 0;
}