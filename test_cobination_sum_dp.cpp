#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int helper(vector<int> arr, int t, int n, vector<int> &dp)

{
    if (t== 0)
    {
        return 1;
    }
    if (t < 0)
    {
        return 0;
    }
    if (dp[t] != -1)
    {
        return dp[t];
    }
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        if(dp[i]!=0){
            ans += helper(arr, t - arr[i], n, dp);

        }

        
    }
    dp[t] = ans;
    return dp[t];
}

void func()
{
    vector<int> arr = {1, 2, 5};
    int t = 5;
    int n = 3;
    vector<int> dp(t + 1, -1);
    int res = helper(arr, t, n, dp);
    cout << res;
}

int main()
{
    func();
    return 0;
}