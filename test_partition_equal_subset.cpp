#include <iostream>
#include <vector>
#include <bits/stdc++.h>
#include <algorithm>

using namespace std;

int helper(vector<int> &arr, int i, int target)
{
    if (target < 0 || i >= arr.size())
    {
        return false;
    }
    if (target == 0)
    {
        return true;
    }
    bool inc = helper(arr, i + 1, target - arr[i]);
    bool exe = helper(arr, i + 1, target);
    return inc || exe;
}

int helper_memo(vector<int> arr, int i, int target, vector<vector<int>> &dp)

{
    if (target < 0 || i >= arr.size())
    {
        return false;
    }
    if (target == 0)
    {
        return true;
    }
    if (dp[i][target] != -1)
    {
        return dp[i][target];
    }

    int inc = helper_memo(arr, i + 1, target - arr[i], dp);
    int exe = helper_memo(arr, i + 1, target, dp);
    dp[i][target] = inc || exe;
    return dp[i][target];
}

bool helper_tab(vector<int> arr, int i, int target)
{
    int n = arr.size();

    vector<vector<int>> dp(n + 1, vector<int>(target + 1, 0));
    for (int i = 0; i <= n; i++)
    {

        dp[i][0] = 1;
    }
    for (int i = n - 1; i >= 0; i--)
    {

        for (int j = 0; j <= target; j++)
        {
            int inc = 0;
            if (j - arr[i] >= 0)
            {

                inc = dp[i + 1][j - arr[i]];
            }

            int exe = dp[i + 1][j];
            dp[i][j] = inc || exe;
        }
    }
    return dp[0][target];
}

int helper_sc(vector<int> arr, int i, int target)
{
    int n = arr.size();

    vector<int> curr(target + 1, 0);
    vector<int> next(target + 1, 0);
    curr[0] = 1;
    next[0] = 1;
  
    for (int i = n - 1; i >= 0; i--)
    {

        for (int j = 0; j <= target; j++)
        {
            int inc = 0;
            if (j - arr[i] >= 0)
            {

                inc = next[j - arr[i]];
            }

            int exe = next[j-0];
            curr[j] = inc || exe;
        }
        next = curr;
    }
    return next[target];
}

void func()
{
    vector<int> arr = {1, 5, 11, 5};
    // vector<int> arr = {5, 8, 3, 7, 9, 1};
    int sum = 0;
    int n = arr.size();
    for (auto x : arr)
    {
        sum += x;
    }
    if (sum % 2 != 0)
    {
        cout << "NO" << " ";
    }
    int half = sum / 2;
    vector<vector<int>> dp(n + 1, vector<int>(sum + 1, -1));
    // long long res1 = helper(arr,0,half);
    // long long res1 = helper_memo(arr,0,half,dp);
    // long long res1 = helper_tab(arr, 0, half);
    long long res1 = helper_sc(arr, 0, half);
    if (res1 == 1)
    {
        cout << " Yes";
    }
}

int main()
{
    func();
    return 0;
}
