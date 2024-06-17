#include <iostream>
#include <vector>
#include <bits/stdc++.h>
#include <algorithm>

using namespace std;

int helper(vector<int> arr, int i, int buy)
{
    if (i >= arr.size())
    {
        return 0;
    }
    int res = 0;
    if (buy)
    {
        res = max(-arr[i] + helper(arr, i + 1, 0), 0 + helper(arr, i + 1, 1));
    }
    if (!buy)
    {
        res = max(arr[i] + helper(arr, i + 1, 1), 0 + helper(arr, i + 1, 0));
    }
    return res;
}

int helper_memo(vector<int> arr, int i, int buy, vector<vector<int>> &dp)

{
    if (i >= arr.size())
    {
        return 0;
    }
    if (dp[i][buy] != -1)
    {
        return dp[i][buy];
    }
    int res = 0;
    if (buy == 1)
    {
        res = max(-arr[i] + helper_memo(arr, i + 1, 0, dp), 0 + helper_memo(arr, i + 1,
                                                                            1, dp));
    }
    else
    {
        res = max(arr[i] + helper_memo(arr, i + 1, 1, dp), 0 + helper_memo(arr, i + 1, 0, dp));
    }
    dp[i][buy] = res;
    return res;
}

int helper_tab(vector<int> arr, int i, int buy)
{
    int n = arr.size();
    vector<vector<int>> dp(n + 1, vector<int>(3, 0));
    for (int i = n - 1; i >= 0; i--)
    {

        for (int j = 0; j <= 1; j++)
        {

            int res = 0;
            if (j == 1)
            {
                res = max(-arr[i] + dp[i + 1][0], 0 + dp[i + 1][1]);
            }
            else
            {
                res = max(arr[i] + dp[i + 1][1], 0 + dp[i + 1][0]);
            }
            dp[i][j] = res;
        }
    }
    return dp[0][1];
}

int helper_sc(vector<int> arr, int i, int buy,int fee)
{
    int n = arr.size();
    vector<int> curr(2 + 1, 0);
    vector<int> next(2 + 1, 0);
    for (int i = n - 1; i >= 0; i--)
    {

        for (int j = 0; j <= 1; j++)
        {

            int res = 0;
            if (j == 1)
            {
                res = max(-arr[i] + next[0]-fee, 0 + next[1]);
            }
            else
            {
                res = max(arr[i] + next[1]
                , 0 + next[0]);
            }
            curr[j] = res;
        }
        next = curr;
    }
    return next[1];
}

void func()
{
    vector<int> arr = {7, 1, 5, 3, 6, 4};
    int res = helper(arr, 0, 1);
    int n = arr.size();
    vector<vector<int>> dp(n + 1, vector<int>(3, -1));
    // res = helper_memo(arr, 0, 1, dp);
    // res = helper_tab(arr, 0, 1);
    res = helper_sc(arr, 0, 1,2);

    cout << res;
}

int main()
{
    func();
    return 0;
}
