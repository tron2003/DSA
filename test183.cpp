#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int helper(vector<int> &arr, int l, int h)
{

    int p = arr[l];
    int i = l - 1;
    int j = h + 1;
    while (true)
    {
        do
        {

            i++;
        } while (arr[i] < p);
        do
        {
            j--;
        } while (arr[j] > p);

        if (i >= j)
        {
            return j;
        }
        swap(arr[i], arr[j]);
    }
}

void func(vector<int> &arr, int l, int h)
{

    if (l < h)
    {
        int p = helper(arr, l, h);
        func(arr, l, p);
        func(arr, p + 1, h);
    }
}

int main()
{
    vector<int> arr = {21, 10, 1, 12, 45};

    func(arr, 0, 4);
    for (auto x : arr)
    {

        cout << x << " ";
    }
    return 0;
}