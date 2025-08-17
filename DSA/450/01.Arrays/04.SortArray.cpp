/************************************************************
 * File:         ReverseTheArray.cpp
 * Author:       Deepesh Soni
 * Created on:   2025-08-06
 * Description:  Given an array which consists of only 0, 1 and 2. Sort the array without using any sorting algo
 * Problem Link:
 * Space Complexity: O(1)   
 * Time Complexity:  O(n) Dutch national Flag problem  
 * 
 * Compiler:     MSVC 19.41, C++17
 * Build:        cl /std:c++17 /EHsc Sort.cpp
 *
 * License:      MIT License (or specify your license)
 ************************************************************/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> Sort(vector<int> &arr)
{
    int n = arr.size();
    int currrentIndex = 0;
    int onesStartIndex = 0;
    int twosStartIndex = n - 1;
    while (currrentIndex <= twosStartIndex)
    {
        if (arr[currrentIndex] == 0)
        {
            std::swap(arr[currrentIndex], arr[onesStartIndex]);
            onesStartIndex++;
            currrentIndex++;
        }
        else if (arr[currrentIndex] == 2)
        {
            std::swap(arr[currrentIndex], arr[twosStartIndex]);
            twosStartIndex--;
        }
        else
        {
            currrentIndex++;
        }
    }

    return arr;
}

int main()
{
    vector<int> arr{0, 1, 1, 0, 0, 2, 1, 0, 2};
    Sort(arr);
    for (auto element : arr)
        cout << element << " ";

    return 0;
}

/*
* Alternate way:
* std::sort() complexity O(nlogn)
*/
