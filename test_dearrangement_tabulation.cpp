#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#define mod 1000000007
long long helper(vector<long long> &dp, int n)
{

    dp[0] = 0;
    dp[1] = 0;
    dp[2] = 1;

    for (int i = 3; i <= n; i++)
    {
        if (dp[i - 1] != INT_MIN && dp[i - 2] != INT_MIN)
            dp[i] = (((i - 1) % mod) * ((dp[i - 1]) % mod + (dp[i - 2]) % mod)) % mod;
    }
    return dp[n];
}

void func()
{
    int n = 5;

    long long res = 0;
    vector<long long> dp(n + 1, INT_MIN);
    res = helper(dp, n);
    cout << res;
}

int main()
{
    func();
    return 0;
}