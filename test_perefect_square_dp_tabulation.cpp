#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int helper(int n, vector<int> &dp)

{

    dp[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j*j <= n;j++){

            int temp = j * j;
            if(i-temp>=0){
                dp[i] = min(dp[i],1+ dp[i - temp]);
            }
        }
    }

    return dp[n];
}

void func()
{

    int n =6;
    vector<int> dp(n + 1, INT_MAX);
    int res = helper(n, dp);
    cout << res;
}

int main()
{
    func();
    return 0;
}