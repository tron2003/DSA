#include <iostream>
#include <vector>
#include <bits/stdc++.h>
#include <algorithm>

using namespace std;

int helper(vector<int> arr, int currlane, int currpos)
{
    int n = arr.size() - 1;
    if (currpos == n)
    {
        return 0;
    }
    if (arr[currpos + 1] != currlane)
    {

        return helper(arr, currlane, currpos + 1);
    }
    else
    {

        int ans = INT_MAX;
        for (int i = 1; i <= 3; i++)
        {
            if (currlane != i && arr[currpos] != i)
            {
                ans = min(ans, 1 + helper(arr, i, currpos+1));
            }
        }
        return ans;
    }
}

int helper_memo(vector<int> arr, int currlane, int currpos, vectortest<vector<int>> &dp)
{
    int n = arr.size() - 1;
    if (currpos == n)
    {
        return 0;
    }
    if (dp[currlane][currpos] != -1)
    {
        return dp[currlane][currpos];
    }
    if (arr[currpos + 1] != currlane)
    {
        return dp[currlane][currpos] = helper_memo(arr, currlane, currpos + 1, dp);
    }
    else
    {
        int ans = INT_MAX;
        for (int i = 1; i <= 3; i++)
        {
            if (currlane != i && arr[currpos] != i)
            {
                ans = min(ans, 1 + helper_memo(arr, i, currpos + 1, dp));
            }
        }
        dp[currlane][currpos] = ans;
        return dp[currlane][currpos];
    }
}


int helper_tab(vector<int> arr)
{
    int n = arr.size() - 1;
    vector<vector<int>> dp(4, vector<int>(n + 1, 1e9));

    dp[0][n] = 0;
    dp[1][n] = 0;
    dp[2][n] = 0;
    dp[3][n] = 0;

    for (int currpos = n - 1; currpos >= 0; currpos--)
    {
        for (int currlane = 1; currlane <= 3; currlane++)
        {
            if (arr[currpos + 1] != currlane)
            {
                dp[currlane][currpos] = dp[currlane][currpos+1];
            }
            else
            {
                int ans = 1e9;
                for (int i = 1; i <= 3; i++)
                {
                    if (currlane != i && arr[currpos] != i)
                    {
                        ans = min(ans, 1 + dp[i][currpos + 1]);
                    }
                }
                dp[currlane][currpos] = ans;
            }
        }
    }

    return min({1 + dp[3][0], dp[2][0], 1 + dp[1][0]});
}


int helper_sc(vector<int> arr)
{
    int n = arr.size() - 1;
    vector<int> curr(4, 1e9);
    vector<int> next(4, 1e9);

    next[0] = 0;
    next[1] = 0;
    next[2] = 0;
    next[3] = 0;

    for (int currpos = n - 1; currpos >= 0; currpos--)
    {
        for (int currlane = 1; currlane <= 3; currlane++)
        {
            if (arr[currpos + 1] != currlane)
            {
                curr[currlane] = next[currlane];
            }
            else
            {
                int ans = 1e9;
                for (int i = 1; i <= 3; i++)
                {
                    if (currlane != i && arr[currpos] != i)
                    {
                        ans = min(ans, 1 + next[currpos+1]);
                    }
                }
                curr[currlane] = ans;
            }
        }
        next = curr;
    }

    return min({1 + next[3], next[2], 1 + next[1]});
}


void func()
{
    // vector<int> cost = {2, 7, 20};
    vector<int> arr = {0,1, 2, 3,0};
    int n = arr.size();
    vector<vector<int>> dp(4, vector<int>(n, -1));

    // int res1 = helper(arr,2,0);
    // int res1 = helper(arr,2,0);
    int res1 = helper_memo(arr, 2, 0, dp);
    // int res1 = helper_tab(arr);
    // int res1 = helper_sc(arr);

    cout << res1;
}

int main()
{
    func();
    return 0;
}
