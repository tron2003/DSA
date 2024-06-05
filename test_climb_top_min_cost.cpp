#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int helper(vector<int>&dp, vector<int> &arr, int n)
{
    if (n == 0)
    {
        return arr[0];
    }
    if (n == 1)
    {
        return arr[1];
    }
    if (dp[n] != -1)
    {
        return dp[n];
    }
    dp[n] = arr[n] + min(helper(dp, arr, n - 1), helper(dp, arr, n - 2));
    return dp[n];
}
void func()
{
    vector<int> arr = {10, 15, 20};
   
    int res = 0;
    int i = 0;
    int n = arr.size();

    vector<int> dp(n, -1);
    res = min(helper(dp, arr, n - 1), helper(dp, arr, n - 2));
    cout << res;
    // return ;
}

int main()
{
    func();

    return 0;
}