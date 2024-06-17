#include <iostream>
#include <vector>
#include <bits/stdc++.h>
#include <algorithm>

using namespace std;

int helper(vector<int> arr, int i, int buy, int tran)
{
    if (i >= arr.size() || tran <= 0)
    {
        return 0;
    }
    int res = 0;
    if (buy && tran >= 1)
    {
        res = max(-arr[i] + helper(arr, i + 1, 0, tran), 0 + helper(arr, i + 1, 1, tran));
    }
    if (!buy && tran >= 1)
    {
        res = max(arr[i] + helper(arr, i + 1, 1, tran - 1), 0 + helper(arr, i + 1, 0, tran));
    }
    return res;
}

int helper_memo(vector<int> arr, int i, int buy, int tran, vector<vector<vector<int>>> &dp)

{
    if (i >= arr.size() || tran <= 0)
    {
        return 0;
    }
    if (dp[i][buy][tran] != -1)
    {
        return dp[i][buy][tran];
    }
    int res = 0;
    if (buy)
    {
        res = max(-arr[i] + helper_memo(arr, i + 1, 0, tran, dp), 0 + helper_memo(arr, i + 1, 1, tran, dp));
    }
    if (!buy)
    {
        res = max(arr[i] + helper_memo(arr, i + 1, 1, tran - 1, dp), 0 + helper_memo(arr, i + 1, 0, tran, dp));
    }
    dp[i][buy][tran] = res;
    return dp[i][buy][tran];
}

int helper_tab(vector<int> arr, int i, int buy)
{
    int n = arr.size();
    vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(3, vector<int>(2 + 1, 0)));
    for (int i = n - 1; i >= 0; i--)
    {

        for (int j = 0; j <= 1; j++)
        {
            for (int k = 0; k <= 2; k++)
            {

                int res = 0;
                if (j == 1)
                {
                    res = max(-arr[i] + dp[i + 1][0][k], 0 + dp[i + 1][1][k]);
                }
                if (j != 1)
                {
                    res = max(arr[i] + dp[i + 1][1][k - 1], 0 + dp[i + 1][0][k]);
                }
                dp[i][j][k] = res;
            }
        }
    }
    return dp[0][1][2];
}

int helper_sc(vector<int> arr, int i, int buy)
{
    int n = arr.size();
    vector< vector<int>>curr(2 + 1, vector<int>(3, 0));
    vector< vector<int>>next(2 + 1, vector<int>(3, 0));
    for (int i = n - 1; i >= 0; i--)
    {

        for (int j = 0; j <= 1; j++)
        {
            for (int k = 0; k <= 2; k++)
            {

                int res = 0;
                if (j == 1)
                {
                    res = max(-arr[i] +next[0][k], 0 +next[1][k]);
                }
                if (j != 1)
                {
                    res = max(arr[i] +next[1][k - 1], 0 +next[0][k]);
                }
                curr[j][k] = res;
            }

        }
        next = curr;
    }
    return next[1][2];
}

void func()
{
    vector<int> arr = {7, 1, 5, 3, 6, 4};
    int res = 0;
    // res = helper(arr, 0, 1, 2);
    int n = arr.size();
    vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(3, vector<int>(2 + 1, -1)));
    // res = helper_memo(arr, 0, 1, 2, dp);
    // res = helper_tab(arr, 0, 1);
    res = helper_sc(arr, 0, 1);

    cout << res;
}

int main()
{
    func();
    return 0;
}
