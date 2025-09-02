/************************************************************
 * Author:            Deepesh Soni
 * Description:
 * Problem Link:
 * Time Complexity:
 * Space Complexity:
 *
 * Compiler:          MSVC 19.41, C++20
 * Build:             cl /std:c++17 /EHsc MaxAndMinElementInaay.cpp
 *
 * License:           MIT License (or specify your license)
 ************************************************************/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int maxProfit(vector<int> &prices)
{
    int buy = prices[0];
    int profit = 0;

    for (int i = 1; i < prices.size(); ++i)
    {
        if (prices[i] < buy)
            buy = prices[i];
        else
            profit = max(profit, prices[i] - buy);
    }

    return profit;
}

int main()
{
    vector<int> nums{7, 1, 5, 3, 6, 4};
    cout << maxProfit(nums);

    return 0;
}