#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int helper(vector<int> arr, int n, int a, vector<int> &dp)
{
    if (a < 0)
    {
        return INT_MAX;
    }
    if (a == 0)
    {
        return 0;
    }
    for (int i = 0; i < n; i++)
    {
        int temp = helper(arr, n, a - arr[i], dp);
        if (temp != INT_MAX)
        {

            dp[a] = min(dp[a], 1 + temp);
        }
    }
    return dp[a];
}

void func()
{
    vector<int> arr = {1, 2, 3};
    int n = arr.size();
    int res = 0;
    int a = 7;
    int i = 0;
    vector<int> dp(a + 1, INT_MAX);
    res = helper(arr, n, a, dp);
    cout << res;
}

int main()
{
    func();
    return 0;
}