#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int func(vector<int> arr, int n)
{
    vector<int> dp(n, INT_MAX);
    dp[0] = 0;
    for (int i = 1; i <n; i++)
    {

        for (int j = 0; j < i; j++)
        {
            if(dp[j]!=INT_MAX &&i<=j+arr[j]){
                dp[i] = min(dp[i], dp[j] + 1);
            }
        }
    }
    return dp[n -1];
}

int main()
{
    vector<int> arr = {4,1,5,3,1,3,2,1,8};
    cout << func(arr,arr.size());
    return 0;
}