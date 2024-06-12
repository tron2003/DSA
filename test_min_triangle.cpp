#include <iostream>
#include <vector>
#include <bits/stdc++.h>
#include <algorithm>

using namespace std;

int helper(vector<int> arr, int i, int j)
{
    if (i + 1 == j)
    {
        return 0;
    }
    int res = INT_MAX;
    for (int k = i + 1; k < j; k++)
    {

        res = min({res, (arr[i] * arr[j] * arr[k]) + helper(arr, i, k) + helper(arr, k, j)});
    }
    return res;
}
int helper_memo(vector<int> arr, int i, int j, vector<vector<int>> &dp)
{
    if (i + 1 == j)
    {
        return 0;
    }
    if (dp[i][j] != -1)
    {
        return dp[i][j];
    }
    int res = INT_MAX;
    for (int k = i + 1; k < j; k++)
    {

        res = min({res, (arr[i] * arr[j] * arr[k]) + helper_memo(arr, i, k, dp) + helper_memo(arr, k, j, dp)});
    }
    dp[i][j] = res;
    return dp[i][j];
}
int helper_tab(vector<int> arr)
{
    int n = arr.size();
    vector<vector<int>> dp(n, vector<int>(n, 0));
    for (int i = n - 1; i >= 0; i--)
    {

        for (int j = i + 2; j < n; j++)
        {
            int res = INT_MAX;
            for (int k = i + 1; k < j; k++)
            {

                res = min({res, (arr[i] * arr[j] * arr[k]) +dp[i][k]+ dp[k][j]});
            }
            dp[i][j] = res;
        }
    }
    return dp[0] [n - 1];
}

void func()
{
    // vector<int> cost = {2, 7, 20};
    vector<int> arr = {1, 2, 3};
    int n = arr.size();

    int res = 0, res1;
    vector<vector<int>> dp(n, vector<int>(n, -1));
    int i = 0;
    int j = 0;
    // res1 = helper_memo(arr, 0,n-1,dp);
    res1 = helper_tab(arr);

    cout << res1;
}

int main()
{
    func();
    return 0;
}
