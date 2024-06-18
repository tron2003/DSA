#include <iostream>
#include <vector>
#include <bits/stdc++.h>
#include <algorithm>

using namespace std;

int helper(string s1, int i, string s2, int j)
{

    int m = s1.size();
    int n = s2.size();
    if (i >= m || j >= n)
    {

        return 0;
    }
    int res = 0;
    if (s1[i] == s2[j])
    {
        res = 1 + helper(s1, i + 1, s2, j + 1);
    }
    else
    {
        res = max(helper(s1, i + 1, s2, j), helper(s1, i, s2, j + 1));
    }
    return res;
}

int helper_memo(string s1, int i, string s2, int j, vector<vector<int>> &dp)

{

    int m = s1.size();
    int n = s2.size();
    if (i >= m || j >= n)
    {

        return 0;
    }
    if (dp[i][j] != -1)
    {
        return dp[i][j];
    }
    int res = 0;
    if (s1[i] == s2[j])
    {
        res = 1 + helper(s1, i + 1, s2, j + 1);
    }
    else
    {
        res = max(helper(s1, i + 1, s2, j), helper(s1, i, s2, j + 1));
    }
    dp[i][j] = res;
    return res;
}

int helper_tab(string s1, string s2)
{
    int n = s1.size();
    int m = s2.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = m - 1; j >= 0; j--)
        {

            int res = 0;
            if (s1[i] == s2[j])
            {
                res = 1 + dp[i + 1][j + 1];
            }
            else
            {
                res = max(dp[i + 1][j], dp[i][j + 1]);
            }
            dp[i][j] = res;
        }
    }
    return dp[0][0];
}

int helper_sc(string s1, string s2)
{
    int n = s1.size();
    int m = s2.size();
    vector<int> next(m + 1, 0);
    vector<int> curr(n + 1, 0);
    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = m - 1; j >= 0; j--)
        {

            int res = 0;
            if (s1[i] == s2[j])
            {
                res = 1 + next[j + 1];
            }
            else
            {
                res = max(next[j], curr[j + 1]);
            }
            curr[j] = res;
        }
        next = curr;
    }
    return curr[0];
}

void func()
{

    string s1 = "abcde";
    string s2 = "ace";
    // int res = helper(s1, 0, s2, 0);
    vector<vector<int>> dp(s1.size() + 1, vector<int>(s2.size() + 1, -1));
    // int res = helper_memo(s1, 0, s2, 0, dp);
    // int res = helper_tab(s1,  s2);
    int res = helper_sc(s1, s2);

    cout << res;
}

int main()
{
    func();
    return 0;
}
