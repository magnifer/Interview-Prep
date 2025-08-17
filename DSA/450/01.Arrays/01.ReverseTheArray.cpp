/************************************************************
 * File:        ReverseTheArray.cpp
 * Author:      Deepesh Soni
 * Created on:  2025-08-06
 * Description: REverse the elements in an array
 *
 * Compiler:    MSVC 19.41, C++17
 * Build:       cl /std:c++17 /EHsc MaxAndMinElementInArray.cpp
 *
 * License:     MIT License (or specify your license)
 ************************************************************/

#include <iostream>
#include <vector>
using namespace std;

vector<int> ReverseTheArray(vector<int> &arr)
{
    int n = arr.size();
    for (int i = 0; i < n / 2; ++i)
    {
        int temp = arr[i];
        arr[i] = arr[n - i - 1];
        arr[n - i - 1] = temp;
    }

    return arr;
}

int main()
{
    vector<int> arr{1, 2, 3, 4, 5, 6};
    auto arr1 = ReverseTheArray(arr);

    for (auto num : arr1)
    {
        cout << num << " ";
    }
    return 0;
}