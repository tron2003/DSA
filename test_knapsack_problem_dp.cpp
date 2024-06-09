#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#define mod 1000000007

int helper(vector<int> w, vector<int> p, vector<vector<int>> &dp, int n, int cap)
{

    if (n == 0)
    {
        if (w[n] <= cap)
        {
            return p[0];
        }
        else
        {
            return 0;
        }
    }
    int inc = 0;
    if (dp[n][cap] != -1)
    {
        return dp[n][cap];
    }
    int exe = 0;
    if (w[n] <= cap)
    {

        inc = p[n] + helper(w, p, dp, n - 1, cap - w[n]);
    }
    exe = helper(w,p,dp,n-1,cap);

    dp[n][cap] = max(inc, exe);

    return dp[n][cap];
}

void func()
{
    vector<int> w = {1, 2, 3, 4, 5};
    vector<int> p = {5, 4, 8, 6};
    int cap = 5;
    int n = w.size();
    // int i = n - 1;
    vector<vector<int>> dp(n + 1, vector<int>(cap + 1, -1));
    int res = helper(w, p, dp, n - 1, cap);
    cout << res;
}

int main()
{
    func();
    return 0;
}