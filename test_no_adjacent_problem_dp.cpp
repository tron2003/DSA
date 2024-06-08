#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int helper(vector<int> arr, vector<int> dp, int n)
{

    if (n <= 0)
    {
        return 0;
    }
    if (n == 0)
    {
        return arr[0];
    }

    dp[n] = max(helper(arr, dp, n - 3) + arr[n - 1], helper(arr, dp, n - 2));

    return dp[n];
}

void func()
{
    vector<int> arr = {3, 2, 7, 10};
    int n = arr.size();
    int res = 0;

    int i = 0;
    vector<int> dp(n + 1, -1);
    res = helper(arr, dp, n);
    cout << res;
}

int main()
{
    func();
    return 0;
}