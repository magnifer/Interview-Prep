/*
 * @author Deepesh Soni
 * Problem: Find if duplicate element exist
 * Time Complexity: O(n)
 * Space Complexity: O(n)
 */

#include <iostream>
#include <stack>
using namespace std;

bool isValid(string s)
{
	stack<char> st;
	for (auto c : s)
	{
		if (c == '(' || c == '[' || c == '{')
			st.push(c);
		else
		{
			if (st.empty() || ((c == ')' && st.top() != '(') ||
							   (c == ']' && st.top() != '[') ||
							   (c == '}' && st.top() != '{')))
			{
				return false;
			}
			st.pop();
		}
	}
	return st.empty();
}

int main()
{
	string s = "[]{}()";
	isValid(s);

	return 0;
}