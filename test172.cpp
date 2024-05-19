#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int func(vector<int> v, int s)
{
    int n = v.size();
    vector<vector<int>> dp(n + 1, vector<int>(1 + s, 0));
    for (int i = 1; i <= n; i++)
    {
        dp[i][0] = 1;
    }
    for (int i = 1; i <= n; i++)
    {

        for (int j = 1; j <= s; j++)
        {

            if (v[i - 1] <= j)
            {

                dp[i][j] = dp[i - 1][j] + dp[i-1][j - v[i - 1]];
            }
            else
            {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    return dp[n][s];
}
int main()
{

    cout << func({10, 5,2,3,6}, 8);
    return 0;
}