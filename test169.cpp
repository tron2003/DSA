#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int func(int n)
{

    vector<int> dp(n+1,0);
    dp[0] = 1;
    for (int i = 1; i <= n;i++){
        dp[i] = 0;
        for (int j = 0; j < i;j++){
            dp[i] += dp[j] * dp[i - j - 1];
        }
    }
        return dp[n];
}

int main()
{
    cout << func(2);
    return 0;
}