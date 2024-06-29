#include <iostream>
#include <vector>
#include <bits/stdc++.h>
#include <algorithm>

using namespace std;

int helper(vector<int> &arr, int k, int i, int sum, vector<vector<int>> &dp)
{

    if (i < 0)
    {

        return sum == k ? 1 : 0;
    }
    if (k < sum && i >= 0)
    {
        return 0;
    }
    if (dp[i][sum] != -1)
    {

        return dp[i][sum];
    }
    int exe = helper(arr, k, i - 1, sum, dp);
    int inc = helper(arr, k, i - 1, sum + arr[i], dp);

    dp[i][sum] = inc || exe;
    return dp[i][sum];
}
bool subsetSumToK(int n, int k, vector<int> &arr)
{

    vector<vector<int>> dp(n + 1, vector<int>(k + 1, -1));
    int res = helper(arr, k, n - 1, 0, dp);
    return res;
    // Write your code here.
}