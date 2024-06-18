#include <iostream>
#include <bits/stdc++.h>

using namespace std;
bool helper(string s1, int i, string s2, int j)
{

    if (i < 0 && j < 0)
    {
        return true;
    }
    if (i >= 0 && j < 0)
    {
        return false;
    }
    if (i < 0 && j >= 0)
    {
        for (int k = 0; k <= j; k++)
        {
            if (s2[k] != '*')
            {
                return false;
            }
        }
        return true;
    }
    int res = 0;
    if (s1[i] == s2[j] || s2[j] == '?')
    {
        res = 0 + helper(s1, i - 1, s2, j - 1);
    }
    else if (s2[i] == '*')
    {
        res = helper(s1, i, s2, j - 1) || helper(s1, i - 1, s2, j);
    }
    else
    {

        return false;
    }
    return res;
}

int helper_memo(string s1, int i, string s2, int j, vector<vector<int>> &dp)

{
    if (i == 0 && j == 0)
    {
        return true;
    }
    if (i > 0 && j == 0)
    {
        return false;
    }
    if (i == 0 && j > 0)
    {
        for (int k = 0; k <= j; k++)
        {
            if (s2[k - 1] != '*')
            {
                return false;
            }
        }
        return true;
    }
    if ((dp[i][j] != -1))
    {
        return dp[i][j];
    }

    int res = 0;
    if (s1[i - 1] == s2[j - 1] || s2[j - 1] == '?')
    {
        res = 0 + helper_memo(s1, i - 1, s2, j - 1, dp);
    }
    else if (s2[i - 1] == '*')
    {
        res = helper_memo(s1, i, s2, j - 1, dp) || helper_memo(s1, i - 1, s2, j, dp);
    }
    else
    {

        return false;
    }
    dp[i][j] = res;
    return res;
}

int helper_tab(string s1, string s2)
{
    int m = s1.size();
    int n = s2.size();

    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
    dp[0][0] = true;

    for (int i = 1; i <= n; i++)
    {
        for (int k = 0; k <= i; k++)
        {
            if (s2[k] != '*')
            {
                dp[0][i] = false;
                break;
            }
        }
        dp[0][i] = true;
    }
    for (int i = 1; i <= m; i++)
    {

        for (int j = 1; j <= n; j++)
        {
            int res = 0;
            if (s1[i - 1] == s2[j - 1] || s2[j - 1] == '?')
            {
                res = 0 + dp[i - 1][j - 1];
                return dp[i][j] = res;
            }
            else if (s2[i - 1] == '*')
            {
                res = dp[i - 1][j] || dp[i][j - 1];
                return dp[i][j] = res;
            }
            else
            {

                return false;
            }
        }
    }
  
}

int helper_sc(string s1, string s2)
{
    int m = s1.size();
    int n = s2.size();

    vector<int> prev(n + 1, 0);
    vector<int> curr(n + 1, 0);
    prev[0] = true;

    for (int i = 1; i <= n; i++)
    {
        for (int k = 0; k <= i; k++)
        {
            if (s2[k] != '*')
            {
                prev[i] = false;
                break;
            }
        }
        prev[i] = true;
    }
    for (int i = 1; i <= m; i++)
    {

        for (int j = 1; j <= n; j++)
        {
            int res = 0;
            if (s1[i - 1] == s2[j - 1] || s2[j - 1] == '?')
            {
                res = 0 +prev[j - 1];
                return curr[j] = res;
            }
            else if (s2[i - 1] == '*')
            {
                res = prev[j] || curr[j - 1];
                return curr[j] = res;
            }
            else
            {

                return false;
            }
        }
        prev = curr;
    }
    return prev[0];
}

void func()
{

    string s1 = "abcde";
    string s2 = "a*c?e";
    if (s1.length() != s2.length())
    {
        cout << "not possible";
        return;
    }
    // if (s2.length() == 0)
    // {
    //     cout << s1.length();
    // }
    // int res = helper(s1, s1.length() - 1, s2, s2.length() - 1);
    vector<vector<int>> dp(s1.size() + 1, vector<int>(s2.size() + 1, -1));
    // int res = helper_memo(s1, 0, s2, 0, dp);
    // int res = helper_tab(s1, s2);
    int res = helper_sc(s1, s2);

    cout << res;
}

int main()
{
    func();
    return 0;
}
