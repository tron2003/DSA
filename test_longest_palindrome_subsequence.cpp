#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int helper(string s1, int i, string s2, int j)
{

    int m = s1.size();
    int n = s2.size();
    if (i == m)
    {
        return s2.length() - j;
    }
    if (j == n)
    {
        return s1.length() - i;
    }
    int res = 0;
    if (s1[i] == s2[j])
    {
        res = 0 + helper(s1, i + 1, s2, j + 1);
    }
    else
    {
        // insert case
        int insert = 1 + helper(s1, i, s2, j + 1);
        // delete
        int del = 1 + helper(s1, i + 1, s2, j);
        // replce
        int rep = 1 + helper(s1, i + 1, s2, j + 1);
        res = min({insert, del, rep});
    }
    return res;
}

int helper_memo(string s1, int i, string s2, int j, vector<vector<int>> &dp)

{

    int m = s1.size();
    int n = s2.size();
    if (i == m)
    {
        return s2.length() - j;
    }
    if (j == n)
    {
        return s1.length() - i;
    }
    if (dp[i][j] != -1)
    {
        return dp[i][j];
    }
    int res = 0;
    if (s1[i] == s2[j])
    {
        res = 0 + helper_memo(s1, i + 1, s2, j + 1,dp);
    }
    else
    {
        // insert case
        int insert = 1 + helper_memo(s1, i, s2, j + 1,dp);
        // delete
        int del = 1 + helper_memo(s1, i + 1, s2, j,dp);
        // replce
        int rep = 1 + helper_memo(s1, i + 1, s2, j + 1,dp);
        res = min({insert, del, rep});
    }
    dp[i][j] = res;
    return res;
}

int helper_tab(string s1, string s2)
{
    int m = s1.size();
    int n = s2.size();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
    for (int i = 0; i < m; i++)
    {
        dp[i][n] = s1.length() - i;
    }
    for (int j = 0; j < n; j++)
    {
        dp[m][j] = s2.length() - j;
    }
    for (int i = m - 1; i >= 0; i--)
    {
        for (int j = n - 1; j >= 0; j--)
        {
            int res = 0;
            if (s1[i] == s2[j])
            {
                res = dp[i + 1][j + 1];
            }
            else
            {
                // insert case
                int insert = 1 + dp[i][j + 1];
                // delete
                int del = 1 + dp[i + 1][j];
                // replce
                int rep = 1 + dp[i + 1][j + 1];
                res = min({insert, del, rep});
            }
            dp[i][j] = res;
        }
    }
    return dp[0][0];
}

int helper_sc(string s1, string s2)
{
    int m = s1.size();
    int n = s2.size();
    vector<int> next(n + 1, 0);
    vector<int> curr(n + 1, 0);
    for (int i = 0; i < m; i++)
    {
    }
    for (int j = 0; j < n; j++)
    {
        next[j] = s2.length() - j;
    }
    for (int i = m - 1; i >= 0; i--)
    {
        curr[n] = s1.length() - i;
        for (int j = n - 1; j >= 0; j--)
        {
            int res = 0;
            if (s1[i] == s2[j])
            {
                res = next[j + 1];
            }
            else
            {
                // insert case
                int insert = 1 + curr[j + 1];
                // delete
                int del = 1 + next[j];
                // replce
                int rep = 1 + next[j + 1];
                res = min({insert, del, rep});
            }
            curr[j] = res;
        }
        next = curr;
    }
    return curr[0];
}

void func()
{

    string s1 = "horse";
    string s2 = "ros";
  if(s1.length()==0){
      cout<< s2.length();
  }
  if(s2.length()==0){
      cout<< s1.length();
  }
    // int res = helper(s1, 0, s2, 0);
    vector<vector<int>> dp(s1.size() + 1, vector<int>(s2.size() + 1, -1));
    int res = helper_memo(s1, 0, s2, 0, dp);
    // int res = helper_tab(s1, s2);
    // int res = helper_sc(s1, s2);

    cout << res;
}

int main()
{
    func();
    return 0;
}
