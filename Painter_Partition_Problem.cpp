#include<bits/stdc++.h>
#include <iostream>

using namespace std;

bool ischeck(vector<int> &arr, int n, int k, int mid)
{
    int count = 1;
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] + sum <= mid)
        {
            sum += arr[i];
        }
        else
        {
            count++;
            if (count > k || arr[i] > mid)
            {
                return false;
            }
            sum = arr[i];
        }
    }
    return true;
}

int findLargestMinDistance(vector<int> &arr, int k)
{
    int n = arr.size();
    if (k > n)
    {
        return -1;
    }
    int l = 0;
    int h = 0;
    for (auto x : arr)
    {
        h += x;
        l = max(x, l);
    }
    int res = -1;

    while (l <= h)
    {
        int mid = l + (h - l) / 2;
        if (ischeck(arr, n, k, mid))
        {
            res = mid;
            h = mid - 1;
        }
        else
        {
            l = mid + 1;
        }
    }
    return res;
}

int main()
{
    string input;
    getline(cin, input);
   
    vector<int> arr1 = {12, 34, 67, 90};
    int k1 = 2;
    cout << "Test Case 1: " << findLargestMinDistance(arr1, k1) << endl; // Expected output: 113

    return 0;
}
