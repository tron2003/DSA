#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int helper(int n,vector<int>&dp)

{

    if (n == 0)
    {
        return 0;
    }
    if(dp[n]!=-1){
        return dp[n];
    }
    int ans = n;
    for (int i = 1; i * i <= n; i++)
    {
        int temp = i * i;
        ans = min(ans, 1 + helper(n - temp,dp));
    }
    dp[n] = ans;
    return dp[n];
}

void func()
{
   
    int n = 6;
    vector<int> dp(n + 1, -1);
    int res = helper(n,dp);
    cout << res;
}

int main()
{
    func();
    return 0;
}