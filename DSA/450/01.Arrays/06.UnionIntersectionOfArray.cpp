/************************************************************
 * File:         UnionIntersectionOfaay.cpp
 * Author:       Deepesh Soni
 * Created on:   2025-08-06
 * Description:  Find the Union and Intersection of the two sorted aays.
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

vector<int> Union(const vector<int> &a, const vector<int> &b)
{
    vector<int> res;
    int i = 0, j = 0;
    int aSize = a.size(), bSize = b.size();

    while (i < aSize && j < bSize)
    {
        int valA = a[i];
        int valB = b[j];

        if (valA < valB)
        {
            if (res.empty() || res.back() != valA)
                res.push_back(valA);
            ++i;
        }
        else if (valA > valB)
        {
            if (res.empty() || res.back() != valB)
                res.push_back(valB);
            ++j;
        }
        else
        {
            if (res.empty() || res.back() != valA)
                res.push_back(valA);
            ++i;
            ++j;
        }
    }

    while (i < aSize)
    {
        if (res.empty() || res.back() != a[i])
            res.push_back(a[i]);
        ++i;
    }

    while (j < bSize)
    {
        if (res.empty() || res.back() != b[j])
            res.push_back(b[j]);
        ++j;
    }

    return res;
}

vector<int> Intersection(const vector<int> &a, const vector<int> &b)
{
    vector<int> res;
    int i = 0, j = 0;
    int aSize = a.size();
    int bSize = b.size();

    while (i < aSize && j < bSize)
    {
        int valA = a[i];
        int valB = b[j];

        if (valA < valB)
            ++i;
        else if (valA > valB)
            ++j;
        else
        {
            if (res.empty() || res.back() != valA)
                res.push_back(valA);

            while (i < aSize && a[i] == valA)
                ++i;
            while (j < bSize && b[j] == valB)
                ++j;
        }
    }

    return res;
}

int main()
{
    vector<int> a{0, -1, 7, -1, -1, 0, 6, 2, 3, 4, 2};
    vector<int> b{0, 2, 7, -1, 3, 8, 9, 10};
    std::sort(a.begin(), a.end());
    std::sort(b.begin(), b.end());

    for (auto element : a)
        cout << element << " ";
    cout << "\n";
    for (auto element : b)
        cout << element << " ";
    cout << "\n";

    auto resUnion = Union(a, b);
    for (auto element : resUnion)
        cout << element << " ";

    cout << "\n";
    auto resIntersection = Intersection(a, b);
    for (auto element : resIntersection)
        cout << element << " ";

    return 0;
}