#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int func(int e,int f){

    vector<vector<int>> dp(f + 1, vector<int>(e + 1,0));
    for (int i = 0; i <= f;i++){
        dp[i][1] = i;
    }
    for (int i = 0; i <= e;i++){
        dp[1][i] = 1;
    }
    for (int i = 2; i <= f;i++){

        for (int j = 2; j <= e;j++){

            dp[i][j] = INT_MAX;
            for (int x = 1; x <= i;x++){
                dp[i][j] = min(dp[i][j], 1 + max(dp[i-x][j],dp[x-1][j-1]));
            }
        }
    }

        return dp[f][e];
}


int main(){
    cout << func(2, 10);
    return 0;
}