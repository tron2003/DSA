#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int func(vector<int> arr, int n)
{

    vector<int> dp(n + 1, 0);
    dp[1] = arr[0];
    dp[2] = max(arr[0], arr[1]);
    for (int i = 2; i <= n; i++)
    {

        dp[i] = max(dp[i], max(dp[i - 1], dp[i-2]+arr[i - 1]));
    }
    return dp[n];
}

int main()
{
    cout << func({1, 10, 2}, 3);
    return 0;
}