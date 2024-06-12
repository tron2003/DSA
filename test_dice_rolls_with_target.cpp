#include <iostream>
#include <vector>
#include <bits/stdc++.h>
#include <algorithm>

using namespace std;

long long helper(int d, int f, int x)
{
    if (d == 0 && x == 0)
    {
        return 1;
    }
    if (x < 0)
    {
        return 0;
    }
    if (d == 0 && x != 0)
    {
        return 0;
    }
    if (x == 0 && d != 0)
    {
        return 0;
    }

    long long inc = 0;
    for (int i = 1; i <= f; i++)
    {

        inc += helper(d - 1, f, x - i);
    }
    return inc;
}

long long helper_memo(int d, int f, int x, vector<vector<long long>> &dp)

{
    if (d == 0 && x == 0)
    {
        return 1;
    }
    if (x < 0)
    {
        return 0;
    }
    if (d == 0 && x != 0)
    {
        return 0;
    }
    if (x == 0 && d != 0)
    {
        return 0;
    }
    if (dp[d][x] != -1)
    {
        return dp[d][x];
    }

    long long inc = 0;
    for (int i = 1; i <= f; i++)
    {

        inc += helper_memo(d - 1, f, x - i, dp);
    }
    dp[d][x] = inc;
    return dp[d][x];
}

long long helper_tab(int d, int f, int x)
{

    vector<vector<long long>> dp(d + 1, vector<long long>(x + 1, 0));
    dp[0][0] = 1;
    for (int i = 1; i <= d; i++)
    {
        for (int j = 1; j <= x; j++)
        {

            long long ans = 0;
            for (int k = 1; k <= f; k++)
            {
                if (j - k >= 0)
                {
                    ans += dp[i - 1][j - k];
                }
            }
            dp[i][j] = ans;
        }
    }
    return dp[d][x];
}

int helper_sc(int d, int f, int x)
{

    vector<int> prev(x + 1, 0);
    vector<int> curr(x + 1, 0);
    prev[0] = 1;
    for (int i = 1; i <= d; i++)
    {
        for (int j = 1; j <= x; j++)
        {

            long long ans = 0;
            for (int k = 1; k <= f; k++)
            {
                if (j - k >= 0)
                {
                    ans += prev[j - k];
                }
            }
            curr[j] = ans;
        }
        prev = curr;
    }
    return prev[x];
}

void func()
{
    // vector<int> arr = {1, 2, 3, 4, 5, 6};
    // vector<int> arr = {5, 8, 3, 7, 9, 1};
    int m = 6;
    int n = 3;
    int x = 12;
    vector<vector<long long>> dp(m + 1, vector<long long>(x + 1, -1));
    // long long res1 = helper(m, n, x);
    // long long res1 = helper_memo(m, n, x, dp);
    // int res1 = max(helper_memo(arr, dp, 0, k - 1, k / 3), helper_memo(arr, dp2, 1, k, k / 3));
    // long long res1 = helper_tab(m, n, x);
    long long res1 = helper_sc(m, n, x);
    // int res1 = helper_sc(arr);

    cout << res1;
}

int main()
{
    func();
    return 0;
}
