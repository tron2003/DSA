#include <iostream>
#include <vector>
#include <bits/stdc++.h>
#include <algorithm>

using namespace std;

int helper(vector<int> arr, int i, int prev)
{
    if (i >= arr.size())
    {

        return 0;
    }
    int inc = 0;
    if (prev == -1 || arr[i] > arr[prev])
    {

        inc = 1 + helper(arr, i + 1, i);
    }
    int exe = helper(arr, i + 1, prev);
    int res = max(inc, exe);
    return res;
}

int helper_memo(vector<int> arr, int i, int prev, vector<int> &dp)
{
    int n = arr.size();
    if (i >= arr.size())
    {

        return 0;
    }
    if (dp[i] != -1)
    {
        return dp[i];
    }
    int inc = 0;
    if (prev == -1 || arr[i] > arr[prev])
    {

        inc = 1 + helper_memo(arr, i + 1, i, dp);
    }
    int exe = helper_memo(arr, i + 1, prev, dp);
    int res = max(inc, exe);
    dp[i] = res;
    return dp[i];
}

int helper_memo1(vector<int> arr, int i, int prev, vector<vector<int>> &dp)
{
    int n = arr.size();
    if (i >= n)
    {

        return 0;
    }
    if (dp[i][prev + 1] != -1)
    {
        return dp[i][prev + 1];
    }
    int inc = 0;
    if (prev == -1 || arr[i] > arr[prev])
    {

        inc = 1 + helper_memo1(arr, i + 1, i, dp);
    }
    int exe = helper_memo1(arr, i + 1, prev, dp);
    int res = max(inc, exe);
    dp[i][prev + 1] = res;
    return dp[i][prev + 1];
}

int helper_tab(vector<int> arr)
{
    int n = arr.size();
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
    for (int curr = n - 1; curr >= 0; curr--)
    {

        for (int prev = curr - 1; prev >= -1; prev--)
        {

            int inc = 0;
            if (prev == -1 || arr[curr] > arr[prev])
            {
                inc = 1 + dp[curr + 1][curr + 1];
            }
            int exe = dp[curr + 1][prev + 1];
            int res = max(inc, exe);
            dp[curr][prev + 1] = res;
            // return dp[curr][prev];
        }
    }
    return dp[0][0];
}

int helper_sc(vector<int> arr)
{

    int n = arr.size();
    vector<int> curr1(n + 1, 0);
    vector<int> next1(n + 1, 0);
    for (int curr = n - 1; curr >= 0; curr--)
    {

        for (int prev = curr - 1; prev >= -1; prev--)
        {

            int inc = 0;
            if (prev == -1 || arr[curr] > arr[prev])
            {
                inc = 1 + next1[curr + 1];
            }
            int exe = next1[prev + 1];
            int res = max(inc, exe);
            curr1[prev + 1] = res;
            // return dp[curr][prev];
        }
        next1 = curr1;
    }
    return next1[0];
}

int helper_sc1(vector<int> arr)
{

    int n = arr.size();
    if (n == 0)
    {
        return 0;
    }
    vector<int> ans;
    ans.push_back(arr[0]);
    for (int i = 1; i < n; i++)
    {
        if (arr[i] > arr.back())
        {
            ans.push_back(arr[i]);
        }
        else
        {
            int idx = lower_bound(ans.begin(), ans.end(), arr[i]) - arr.begin();
            ans[idx] = arr[i];
        }
    }

    return arr.size();
}
void func()
{
    vector<int> arr = {2, 57, 20};
    // vector<int> arr = {5, 8, 3, 7, 9, 1};
    int n = arr.size();

    int prev = -1;

    vector<int> dp(n + 1, -1);
    // vector<vector<int>> dp(n, vector<int>(n + 1, -1));

    // int res1 = helper(arr, 0, prev);
    // int res1 = helper_memo(arr, 0, prev, dp);
    // int res1 = helper_memo1(arr, 0, prev, dp);
    // int res1 = helper_tab(arr);
    int res1 = helper_sc1(arr);

    cout << res1;
}

int main()
{
    func();
    return 0;
}
