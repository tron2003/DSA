#include <iostream>
#include <vector>
#include <bits/stdc++.h>
#include <algorithm>

using namespace std;

int helper2(vector<int> arr, int i, int end, int n)
{

    if (i >= end || n == 0)
    {
        return 0;
    }
    int inc = arr[i] + helper2(arr, i + 2, end, n - 1);
    int exe = 0 + helper2(arr, i + 1, end, n);
    return max(inc, exe);
}

int helper(vector<int> arr)
{
    int k = arr.size();
    int case1 = helper2(arr, 0, k - 1, k / 3);
    int case2 = helper2(arr, 1, k, k / 3);
    return max(case1, case2);
}

int helper_memo(vector<int> arr, vector<vector<int>> &dp, int i, int end, int n)
{
    if (i >= end || n == 0)
    {
        return 0;
    }
    if (dp[i][n] != -1)
    {
        return dp[i][n];
    }
    int inc = arr[i] + helper_memo(arr, dp, i + 2, end, n - 1);
    int exe = 0 + helper_memo(arr, dp, i + 1, end, n);
    dp[i][n] = max(inc, exe);
    return dp[i][n];
}

int helper_tab(vector<int> arr)
{
    int k = arr.size();
    vector<vector<int>> dp(k + 2, vector<int>(k / 3 + 1, 0));

    vector<vector<int>> dp2(k + 2, vector<int>(k / 3 + 1, 0));

    for (int i = k - 2; i >= 0; i--)
    {

        for (int j = 1; j <= k / 3; j++)
        {

            int inc = arr[i] + dp[i + 2][j - 1];
            int exe = 0 + dp[i + 1][j];
            dp[i][j] = max(inc, exe);
        }
    }
    for (int i = k - 1; i >= 1; i--)
    {

        for (int j = 1; j <= k / 3; j++)
        {

            int inc = arr[i] + dp2[i + 2][j - 1];
            int exe = 0 + dp2[i + 1][j];
            dp2[i][j] = max(inc, exe);
        }
    }
    return max(dp[0][k / 3], dp2[1][k / 3]);
}

int helper_sc(vector<int> arr)
{

    int k = arr.size();

    vector<int> prev1(k + 2, 0);
    vector<int> curr1(k + 2, 0);
    vector<int> next1(k + 2, 0);
    vector<int> prev2(k + 2, 0);
    vector<int> curr2(k + 2, 0);
    vector<int> next2(k + 2, 0);

    for (int i = k - 2; i >= 0; i--)
    {

        for (int j = 1; j <= k / 3; j++)
        {

            int inc = arr[i] + next1[j - 1];
            int exe = 0 + curr1[j];
            prev1[j] = max(inc, exe);
        }
        next1 = curr1;
        curr1 = prev1;
    }

    for (int i = k - 1; i >= 1; i--)
    {

        for (int j = 1; j <= k / 3; j++)
        {

            int inc = arr[i] + next2[j - 1];
            int exe = 0 + curr2[j];
            prev2[j] = max(inc, exe);
        }
        next2 = curr2;
        curr2 = prev2;
    }
    return max(curr1[k / 3], curr2[k / 3]);
}

void func()
{
    vector<int> arr = {1, 2, 3, 4, 5, 6};
    // vector<int> arr = {5, 8, 3, 7, 9, 1};
    int k = arr.size();

    // vector<int> dp(n + 1, -1);
    vector<vector<int>> dp(k, vector<int>(k, -1));
    vector<vector<int>> dp2(k, vector<int>(k, -1));

    // int res1 = helper(arr);
    // int res1 = max(helper_memo(arr, dp, 0, k - 1, k / 3), helper_memo(arr, dp2, 1, k, k / 3));
    // int res1 = helper_tab(arr);
    int res1 = helper_sc(arr);

    cout << res1;
}

int main()
{
    func();
    return 0;
}
