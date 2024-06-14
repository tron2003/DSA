#include <iostream>
#include <vector>
#include <bits/stdc++.h>
#include <algorithm>

using namespace std;

int helper(int n)

{
    if (n <= 1)
    {
        return 1;
    }
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        ans += helper(i - 1) * helper(n - i);
    }
    return ans;
}

int helper_memo(int n, vector<int> &dp)

{

    if (n <= 1)
    {
        return 1;
    }
    if (dp[n] != -1)
    {
        return dp[n];
    }
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        ans += helper_memo(i - 1, dp) * helper_memo(n - i, dp);
    }
    dp[n] = ans;
    return dp[n];
}

int helper_tab(int n)
{

    vector<int> dp(n + 1, 0);
    dp[0] = 1;
    dp[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        int ans = 0;
        for (int j = 1; j <=i;j++){

            ans+= dp[j - 1] * dp[i - j];
        }
        dp[i] = ans;
    }

    return dp[n];
}

int fact(int n ){

    if(n<=1){
        return 1;
    }
    return n * fact(n - 1);
}
int helper_sc(int n)
{
    int numerator = fact(2 * n);
    int denominator = fact(n+1)*fact(n);
    int res = numerator / denominator;
    return res;
}

void func()
{
    int n = 4;
    if (n <= 2)
    {
        cout << n << " ";
        return;
    }

    // int ans = helper(n);
    vector<int> dp(n + 1, -1);
    // int ans = helper_memo(n,dp);
    // int ans = helper_tab(n);
    int ans = helper_sc(n);
    cout << ans;
}

int main()
{
    func();
    return 0;
}
