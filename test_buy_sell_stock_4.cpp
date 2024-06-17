#include <iostream>
#include <vector>
#include <bits/stdc++.h>
#include <algorithm>

using namespace std;

int helper(vector<int> arr, int i, int op, int k)
{
    if (i >= arr.size())
    {
        return 0;
    }
    if (op == 2 * k)
    {
        return 0;
    }
    int res = 0;
    if (op % 2 == 0)
    {
        res = max(-arr[i] + helper(arr, i + 1, op + 1, k), 0 + helper(arr, i + 1, op, k));
    }
    if (op % 2 != 0)
    {
        res = max(arr[i] + helper(arr, i + 1, op + 1, k), 0 + helper(arr, i + 1, op, k));
    }
    return res;
}

int helper_memo(vector<int> arr, int i, int op, int k, vector<vector<int>> &dp)

{
    if (i >= arr.size())
    {
        return 0;
    }
    if (op == 2 * k)
    {
        return 0;
    }
    if (dp[i][op] != -1)
    {
        return dp[i][k];
    }
    int res = 0;
    if (op % 2 == 0)
    {
        res = max(-arr[i] + helper_memo(arr, i + 1, op + 1, k, dp), 0 + helper_memo(arr, i + 1, op, k, dp));
    }
    if (op % 2 != 0)
    {
        res = max(arr[i] + helper_memo(arr, i + 1, op + 1, k, dp), 0 + helper_memo(arr, i + 1, op, k, dp));
    }
    dp[i][op] = res;
    return res;
}

int helper_tab(vector<int> arr, int i, int op, int k)
{
    int n = arr.size();
    vector<vector<int>> dp(n + 1, vector<int>(2 * k + 1, 0));
    for (int i = n - 1; i >= 0; i--)
    {

        for (int j = 2 * k; j >= 0; j--)
        {
            int res = 0;
            if (j % 2 == 0)
            {
                res = max(-arr[i] + dp[i+1][j+1], 0 +dp[i+1][j]);
            }
            if (j % 2 != 0)
            {
                res = max(arr[i] +dp[i+1][j+1], 0 +dp[i+1][j]);
            }
            dp[i][j] = res;
        }
    }

    return dp[0][0];
}

int helper_sc(vector<int> arr, int i, int op, int k)
{
    int n = arr.size();
    vector<int> curr(2*k + 1);
    vector<int> next(2 *k+1);
    for (int i = n - 1; i >= 0; i--)
    {

        for (int j = 2 * k; j >= 0; j--)
        {
            int res = 0;
            if (j % 2 == 0)
            {
                res = max(-arr[i] +next[j + 1], 0 + next[j]);
            }
            if (j % 2 != 0)
            {
                res = max(arr[i] + next[j + 1], 0 + next[j]);
            }
            curr[j] = res;
        }
        next = curr;
    }

    return curr[0];
}

void func()
{
    vector<int> arr = {2, 4, 1};
    int res = 0;
    int k = 2;
    res = helper(arr, 0, 0, k);
    int n = arr.size();
    vector<vector<int>> dp(n + 1, vector<int>(2 * k + 1, -1));
    // res = helper_memo(arr, 0, 0, k, dp);
    // res = helper_tab(arr, 0, 0, k);
    res = helper_sc(arr, 0, 1,k);

    cout << res;
}

int main()
{
    func();
    return 0;
}
