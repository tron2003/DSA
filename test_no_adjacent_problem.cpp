#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int helper(vector<int> arr, int n, int i)
{

    if (i >= n)
    {
        return 0;
    }
    if (i == n - 1)
    {
        return arr[n - 1];
    }

    int res = helper(arr, n, i + 2) + arr[i];
    int exe = helper(arr, n, i + 1);

    return max(res, exe);
}

void func()
{
    vector<int> arr = {3, 2, 7, 10};
    int n = arr.size();
    int res = 0;
     
    int i = 0;

    res = helper(arr, n, i);
    cout << res;
}

int main()
{
    func();
    return 0;
}