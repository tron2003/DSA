#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int helper(vector<int> &dp, int n, int a, int b, int c)
{
    dp[0] = 0;
    for (int i = 1; i <= n; i++)
    {

        if (i - a >= 0 )
        {
            dp[i] = max(dp[i], dp[i - a] + 1);
        }
        else if (
            i - b >= 0)
        {
            dp[i] = max(dp[i], dp[i - b] + 1);
        }
        else if (i - c >= 0)
        {
            dp[i] = max(dp[i], dp[i - c] + 1);
        }
    }
    return dp[n];
}

void func()
{
    int n = 11;

    vector<int> dp(n + 1, INT_MIN);
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