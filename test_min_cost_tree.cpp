#include <iostream>
#include <vector>
#include <bits/stdc++.h>
#include <algorithm>

using namespace std;

int helper(vector<int> arr, int l, int r, map<pair<int, int>, int> &mp)
{

    if (l == r)
    {
        return 0;
    }
    int ans = INT_MAX;
    for (int i = l; i < r; i++)
    {
        ans = min(ans, (mp[{l, i}] * mp[{i + 1, r}]) + helper(arr, l, i, mp) + helper(arr, i + 1, r, mp));
    }
    return ans;
}

int helper_memo(vector<int> arr, int l, int r, map<pair<int, int>, int> &mp, vector<vector<int>> &dp)

{

    if (l == r)
    {
        return 0;
    }
    if (dp[l][r] != -1)
    {
        return dp[l][r];
    }
    int ans = INT_MAX;
    for (int i = l; i < r; i++)
    {
        ans = min(ans, (mp[{l, i}] * mp[{i + 1, r}]) + helper_memo(arr, l, i, mp, dp) + helper_memo(arr, i + 1, r, mp, dp));
    }
    dp[l][r] = ans;
    return ans;
}

int helper_tab(int n, vector<int> arr,map<pair<int,int>,int>&mp)
{
    vector<vector<int>> dp(n + 2, vector<int>(n + 2, 0));
    for (int l = n -1; l >= 0; l--)
    {

        for (int r = l + 1; r < n; r++)
        {
            int ans = INT_MAX;
            for (int k = l; k < r; k++)
            {
                ans = min(ans, (mp[{l, k}] * mp[{k + 1, r}]) + dp[l][k] +dp[k+1][r]  );
            }
            dp[l][r] = ans;
        }
    }
    return dp[0][n-1];
}

void func()
{
    vector<int> arr = {6, 2, 4};
    int n = arr.size();
    map<pair<int, int>, int> mp;
    for (int i = 0; i < n; i++)
    {
        mp[{i, i}] = arr[i];
        for (int j = i + 1; j < n; j++)
        {

            mp[{i, j}] = max(arr[j], mp[{i, j - 1}]);
        }
    }
    // int res = helper(arr, 0, n-1,mp);
    // vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
    // int res = helper_memo(arr, 0, n-1,mp,dp);
    int res = helper_tab(n, arr,mp);
    cout << res << "";
}

int main()
{
    func();
    return 0;
}
