#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int helper(int *dp, int n)
{
    if(n==0){
        return 1;
    }
    if(n<=-1){
        return 0;
    }
    dp[n] = helper(dp, n - 1) + helper(dp, n - 2);
    return dp[n];
}
void func(int n)
{

    if (n == 0)
    {
        return;
    }
    int res = 0;
    int i = 0;
    int dp[n + 1] = {-1};
    res=helper(dp, n);
    cout << res;
    // return ;
}

int main()
{
    func(4);

    return 0;
}