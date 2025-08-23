/************************************************************
 * File:         UnionIntersectionOfaay.cpp
 * Author:       Deepesh Soni
 * Created on:   2025-08-06
 * Description:  Rotate and array by k.
 * Problem Link:
 *
 * Compiler:     MSVC 19.41, C++17
 * Build:        cl /std:c++17 /EHsc MaxAndMinElementInaay.cpp
 *
 * License:      MIT License (or specify your license)
 ************************************************************/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void Reverse(vector<int> &arr, int start, int end)
{
    while (start < end)
        swap(arr[start++], arr[end--]);
}

vector<int> RightRotation(vector<int> &arr, int k)
{
    // reverse last k elements.
    // reverse 0 to n-k elements.
    // reverse whole array.
    int n = arr.size();
    k = k % n;

    Reverse(arr, n - k, n - 1);
    for (auto element : arr)
        cout << element << " ";
    cout << endl;

    Reverse(arr, 0, n - k - 1);
    for (auto element : arr)
        cout << element << " ";
    cout << endl;

    Reverse(arr, 0, n - 1);

    return arr;
}

vector<int> LeftRotation(vector<int> &arr, int k)
{

    // reverse last k elements.
    // reverse 0 to n-k elements.
    // reverse whole array.
    int n = arr.size();
    k = k % n;

    Reverse(arr, 0, k - 1);
    for (auto element : arr)
        cout << element << " ";
    cout << endl;

    Reverse(arr, k, n - 1);
    for (auto element : arr)
        cout << element << " ";
    cout << endl;

    Reverse(arr, 0, n - 1);

    return arr;
}

int main()
{
    vector<int> arr{0, 8, 6, 2, 3, 4, 2, 5, 45, 1, 33};
    vector<int> arr1{0, 8, 6, 2, 3, 4, 2, 5, 45, 1, 33};
    int k = 4;

    cout << "Right Rotation:\n";
    RightRotation(arr, k);
    for (auto element : arr)
        cout << element << " ";

    cout << "\nLeft Rotation:\n";
    LeftRotation(arr1, k);
    for (auto element : arr1)
        cout << element << " ";

    return 0;
}