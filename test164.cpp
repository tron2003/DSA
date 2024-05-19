#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int func(int n, int a, int b, int c)
{

    vector<int> dp(n + 1, 0);
    dp[0] = 0;
    for (int i = 1; i <= n; i++)
    {

        dp[i] = -1;
        if (i - a >= 0)
        {
            dp[i] = max(dp[i], dp[i - a]);
        }
        if (i - b >= 0)
        {
            dp[i] = max(dp[i], dp[i - b]);
        }
        if (i - c >= 0)
        {
            dp[i] = max(dp[i], dp[i - c]);
        }
        if (dp[i] != -1)
        {
            dp[i]++;
        }
    }
    return dp[n];
}

int main()
{
    cout << func(5, 1, 2, 3);
    return 0;
}