#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int func(vector<int> arr, int n)
{

    vector<vector<int>> dp(n, vector<int>(n, 0));
    for (int i = 0; i < n - 1; i++)
    {
        dp[i][i+1] = max(arr[i], arr[i + 1]);
    }

    for (int g = 3; g < n;g=g+2){

        for (int i = 0; i + g < n;i++){
            int j = i + g;                                                                                                                                                                                                     
            dp[i][j] = max(arr[i] + min(dp[i + 2][j], dp[i + 1][j - 1]), arr[j] + min(dp[i + 1][j - 1],dp[i][j-2]));
        }
    }
    return dp[0][n-1];
}

int main()
{
    cout << func({20, 5, 4, 6}, 4);
    return 0;
}