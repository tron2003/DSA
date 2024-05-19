#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int func(string str1, string str2)
{
    int m = str1.size();
    int n = str2.size();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
    // for (int i = 0; i < m; i++)
    // {

    //     dp[i][0] = 0;
    // }

    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {

            if (str1[i - 1] ==str2[j - 1])
            {

                dp[i][j] = 1 + dp[i-1][j-1];
            }
            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j-1]);
            }
        }
    }
    return dp[m][n];
}

int main()
{
    string X = "AGGAB";
    string Y = "GXTXAYB";

    // Lengths of the input strings
    int m = X.length();
    int n = Y.length();

    // Initialize the memoization table
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));

    // Call the function to compute the length of LCS
    cout << "Length of Longest Common Subsequence: " << func(X, Y ) << endl;

    return 0;
}