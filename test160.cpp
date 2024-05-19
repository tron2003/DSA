#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int func(vector<int> arr, int n, int m)
{
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    for (int i = 1; i <= m; i++)
    {
        dp[0][i] = i;
    }
    for (int i = 1; i <= n; i++)
    {

        for (int j = 1; j <= m; j++)
        {

            if (arr[i] <= j)
            {
                dp[i][j] = min(dp[i - 1][j], 1 + dp[i][j - arr[i]]);
            }
            else
            {

                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    return dp[n][m];
}
int main()
{
    vector<int> arr = {18, 1, 10};
    cout << func(arr, 3, 20);

    return 0;
}