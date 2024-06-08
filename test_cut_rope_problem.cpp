#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int helper(vector<int> &dp, int n, int a, int b, int c)
{

    if (n == 0)
    {
        return 0;
    }
    if (n < 0)
    {
        return INT_MIN;
    }
    if (dp[n] != -1)
    {
        return dp[n];
    }
    dp[n] = max({1 + helper(dp, n - a, a, b, c), 1 + helper(dp, n - b, a, b, c), 1 + helper(dp, n - b, a, b, c)});

    return dp[n];
}

void func()
{
    int n = 11;

    vector<int> dp(n + 1, -1);
    vector<int> arr1;
    vector<int> arr2;

    int res = 0;
    res = helper(dp, 10, 2, 3, 1);
    cout << res;
}

int main()
{
    func();
    return 0;
}