/*
 * @author Deepesh Soni
 * Problem: Find if strings sre Palindrome using two pointer approach
 * Time Complexity: O(n)
 * Space Complexity: O(n)
 */

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

bool isPalindromeWithoutExtraSpace(string s)
{
	int start = 0;
	int end = s.length() - 1;

	while (start < end)
	{
		if (!isalnum(s[start]))
			++start;
		else if (!isalnum(s[end]))
			--end;
		else if (tolower(s[start++] != tolower(s[end--])))
			return false;
	}
	return true;
}

bool isPalindrome(string s)
{
	string str;
	for (auto c : s)
	{
		if (c >= 97 && c <= 122 || c >= 48 && c <= 57)
			str.push_back(c);
		if (c >= 65 && c <= 90)
			str.push_back(tolower(c));
	}

	int length = str.length() - 1;
	for (int i = 0; i < length; i++)
	{
		if (str[i] != str[length - i])
		{
			return false;
		}
	}
	return true;
}

int main()
{
	string input = "anagram";
	isPalindrome(input);
	isPalindromeWithoutExtraSpace(input);

	return 0;
}