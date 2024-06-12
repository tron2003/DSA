#include <iostream>
#include <vector>
#include <bits/stdc++.h>
#include <algorithm>

using namespace std;

int helper(vector<int> arr, int i, int t)
{
    if (i >= arr.size())
    {
        return 0;
    }

    int inc = arr[i] * (t) + helper(arr, i + 1, t + 1);
    int exe = helper(arr, i + 1, t);

    int res = max(inc, exe);
    return res;
}

int helper_memo(vector<int> arr, int i, int t, vector<vector<int>> &dp)
{
    if (i >= arr.size())
    {
        return 0;
    }
    if (dp[i][t] != -1)
    {
        return dp[i][t];
    }
    int inc = arr[i] * (t) + helper_memo(arr, i + 1, t + 1, dp);
    int exe = helper_memo(arr, i + 1, t, dp);

    dp[i][t] = max(inc, exe);
    return dp[i][t];
}

int helper_tab(vector<int> arr)
{
    int n = arr.size();
    vector<vector<int>> dp(n + 1, vector<int>(n+1, 0));

    
    for (int i = n - 1; i >= 0; i--)
    {

        for (int t = i; t >= 0; t--)
        {

            int inc = arr[i] * t + dp[i + 1][t+1];
            int exe = dp[i + 1][t];
            dp[i][t] = max(inc, exe);
        }
    }
    return dp[0][0];
}
int helper_sc(vector<int> arr)
{
    int n = arr.size();
    vector<int> curr(n + 1, 0);
    vector<int> next(n + 1, 0);

    for (int i = n - 1; i >= 0; i--)
    {

        for (int t = i; t >= 0; t--)
        {

            int inc = arr[i] * t + next[i + 1];
            int exe = next[i ];
            curr[t]= max(inc, exe);
        }
        next = curr;
    }
    return next[0];
}
void func()
{
    // vector<int> cost = {2, 7, 20};
    vector<int> arr = {-1, -8, 0,5,-7};
    int n = arr.size();
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
    sort(arr.begin(), arr.end());
    int t = 1;
    // int res1 = helper(arr, 0, t);

    // int res1 = helper_memo(arr, 0, 1, dp);
    int res1 = helper_tab(arr);
    // int res1 = helper_sc(arr);

    cout << res1;
}

int main()
{
    func();
    return 0;
}
