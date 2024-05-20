#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int sum(vector<int> arr, int i, int j)
{
    int res = 0;
    for (auto c = i; c <= j;c++)
    {
        res += arr[c];
    }
    return res;
}

int func(vector<int> arr, int k, int n)
{

    vector<vector<int>> dp(k + 1, vector<int>(n + 1, 0));
    for (int i = 1; i <= n; i++)
    {
        dp[1][i] = sum(arr, 0, i - 1);
    }
    for (int i = 1; i <= k; i++)
    {
        dp[i][1] = arr[0];
    }

    for (int i = 2; i <= k;i++){

        for (int j = 2; j <= n;j++){

            int res = INT_MAX;
            for (int p = 1; p < j;p++){

                res =min(res, max(dp[i - 1][p], sum(arr, p, j - 1)));
            }
            dp[i][j] = res;
        }
    }
    return dp[k][n];
}

int main()
{
    cout << func({12, 34, 67, 90}, 2, 4) << " ";

    return 0;
}