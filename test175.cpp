#include <iostream>
#include <bits/stdc++.h>
using namespace std;
bool isres(string str, int i, int j)
{

    while (i < j)
    {

        if (str[i] != str[j])
        {
            return false;
        }
        i++;
        j--;
    }
    return true;
}
int func(string str, int n)
{

    vector<vector<int>> dp(n,vector<int>(n,0));

    for (int gap = 1; gap < n; gap++)
    {

        for (int i = 0; i + gap < n; i++)
        {

            int j = gap + i;
            if (isres(str, i, j))
            {
                dp[i][j] = 0;
            }
            else
            {
                dp[i][j] = INT_MAX;
                for (int k = i; k < j; k++)
                {

                    dp[i][j] = min(dp[i][j], 1 + dp[i][k] + dp[k + 1][j]);
                }
            }
        }
    }
    return dp[0][n - 1];
}

int main()
{
    cout << func("geek", 4);

    return 0;
}