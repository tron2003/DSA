#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int helper(vector<int> &dp, vector<int> &arr, int n)
{
    dp[0] = arr[0];
    dp[1] = arr[1];
    for (int i = 2; i < n;i++){

        dp[i] = arr[i] + min(dp[n-1], dp[n-2]);
    }
    return min(dp[n-1],dp[n-2]);
}
void func()
{
    vector<int> arr = {10, 15, 20};

    int res = 0;
    int i = 0;
    int n = arr.size();

    vector<int> dp(n, -1);
    res = helper(dp,arr,n);
    cout << res;
    // return ;
}

int main()
{
    func();

    return 0;
}