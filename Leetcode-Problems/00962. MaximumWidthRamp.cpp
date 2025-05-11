#include <iostream>
#include <stack>
#include <vector>

using namespace std;

// Function to implement monotonic decreasing stack
vector<int> monotonicDecreasing(vector<int>& nums) {
    int n = nums.size();
    stack<int> st;
    vector<int> result(n);

    // Traverse the array
    for (int i = 0; i < n; ++i) {
        // While stack is not empty AND top of stack is less than the current element
        while (!st.empty() && st.top() < nums[i]) {
            st.pop();
        }

        // Construct the result array
        if (!st.empty()) {
            result[i] = st.top();
        } else {
            result[i] = -1;
        }

        // Push the current element into the stack
        st.push(nums[i]);
    }

    return result;
}

int main() {
    vector<int> nums = {9,8,1,0,1,9,4,0,4,1};
    vector<int> result = monotonicDecreasing(nums);

    cout << "Monotonic decreasing stack: ";
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}