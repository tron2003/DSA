#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#define mod 1000000007

long long mul(long long a, long long b)
{
    return ((a) % mod * (b) % mod) % mod;
}
long long add(long long a, long long b)
{
    return (a % mod + b % mod) % mod;
}

long long helper(long long a, vector<long long> &dp, long long b)
{

    dp[0]  = 0;
    dp[1] = b;
    dp[2] = add(b, mul(b, b - 1));
    for (int i = 3; i <= a;i++){
        dp[i] = add(mul(dp[i-2],b-1),mul(dp[i-1],b-1) );
    }
    return dp[a];
}  

void func()
{
    int n = 3;
    int k = 2;
    long long res = 0;
    vector<long long> dp(n + 1, 0);
    res = helper(n, dp, k);
    cout << res;
}

int main()
{
    func();
    return 0;
}