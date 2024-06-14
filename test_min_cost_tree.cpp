#include <iostream>
#include <vector>
#include <bits/stdc++.h>
#include <algorithm>

using namespace std;

int helper(int s, int n)

{
    if (s >= n)
    {
        return 0;
    }
    int ans = INT_MAX;

    for (int i = s; i <= n; i++)
    {
        ans += min(ans, i + max(helper(s, i - 1), helper(i + 1, n)));
    }
    return ans;
}

int helper_memo(int s, int n, vector<vector<int>> &dp)

{

    if (s >= n)
    {
        return 0;
    }
    if (dp[s][n] != -1)
    {
        return dp[s][n];
    }
    int ans = INT_MAX;

    for (int i = s; i <= n; i++)
    {
        ans += min(ans, i + max(helper_memo(s, i - 1, dp), helper_memo(i + 1, n, dp)));
    }
    dp[s][n] = ans;
    return ans;
}

int helper_tab(int n)
{
    vector<vector<int>> dp(n + 2, vector<int>(n + 2, 0));
    for (int s = n; s >= 1; s--)
    {
        for (int e = s + 1; e <= n; e++)
        {
            if (s == e)
            {
                continue;
            }
            else
            {
                int ans = INT_MAX;
                // int ans = 0;
                for (int k = s; k <= e; k++)
                {
                    ans += min(ans, k + max(dp[s][k - 1], dp[k + 1][e]));
                }
                dp[s][e] = ans;
            }
        }
    }
    return dp[1][n];
}

int fact(int n)
{

    if (n <= 1)
    {
        return 1;
    }
    return n * fact(n - 1);
}
int helper_sc(int n)
{
}

void func()
{
    int n = 7;
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
    // vector<int> dp(n + 1, -1);
    // int ans = helper(1, n);
    // int ans = helper_memo(1, n,dp);
    int ans = helper_tab(n);
    cout << ans;
}

int main()
{
    func();
    return 0;
}
