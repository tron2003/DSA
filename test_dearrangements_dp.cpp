#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#define mod 1000000007
long long helper(vector<int>&dp,int n)
{

    if (n == 1)
    {
        return 0;
    }
    if (n == 2)
    {
        return 1;
    }
    if(dp[n]!=-1){
        return dp[n];
    }
    dp[n] = ((n - 1) % mod) * ((helper(dp ,n - 2) % mod) + (helper(dp,n - 1) % mod)) % mod;

    return dp[n];
}

void func()
{
    int n = 5;

    long long res = 0;
    vector<int> dp(n+1, -1);
    res = helper(dp,n);
    cout << res;
}

int main()
{
    func();
    return 0;
}