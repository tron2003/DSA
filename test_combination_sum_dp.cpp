#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int helper(vector<int> arr, int t, int n, vector<int> &dp)

{
    dp[0] = 1;
    for (int i = 1; i <= t; i++)
    {
        int ans = 0;
        for (int j = 0; j < n; j++)
        {
            if (i - arr[j] >= 0)
            {

                ans += dp[i - arr[j]];
            }
        }
        dp[i] = ans;
    }
    return dp[t];
}



void func()
{
    vector<int> arr = {1, 2, 5};
    int t = 5;
    int n = 3;
    vector<int> dp(t + 1, 0);
    int res = helper(arr, t, n, dp);
    cout << res;
}

int main()
{
    func();
    return 0;
}