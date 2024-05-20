#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int func(string s1, string s2)
{

    int m = s1.size();
    int n = s2.size();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
    for (int i = 1; i <= m; i++)
    {
        dp[i][0] = i;
    }

    for (int i = 1; i <= n; i++)
    {
        dp[0][i] = i;
    }

    for (int i = 1; i <= m;i++){
        for (int j = 1; j <= n;j++){
          if(s1[i-1]==s2[j-1]){
              dp[i][j] = dp[i - 1][j - 1];
          }
          else{
            dp[i][j]= 1+min({dp[i-1][j],dp[i-1][j-1],dp[i][j-1]});
          }
        }
    }
    return dp[m ][n ];
}

int main()
{
    cout << func("KANISH", "TANIUH");
    return 0;
}