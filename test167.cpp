#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int func(vector<int>v,vector<int>w,int n,int a){
    vector<vector<int>> dp(n + 1, vector<int>(1 + a, 0));
    for (int i = 1; i <= n;i++){

        for (int j = 1; j <= a;j++){

            if(w[i-1]<=j){

                dp[i][j] = max(v[i -1]+dp[i][j-w[i-1]],dp[i-1][j]);
            }
            else{
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    return dp[n][a];
}
int main(){

    cout << func({10, 40, 30, 50}, {5, 4, 6, 3}, 4, 10);
    return 0;
}