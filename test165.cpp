#include<iostream>
#include<bits/stdc++.h>
using namespace std;


int func(vector<int>arr,int n,int s){
    vector<vector<int>> dp(n + 1, vector<int>(s + 1, 0));
    for (int i = 0; i <= n;i++){
        dp[i][0] = 1;
    }
    for (int i = 1; i <= n;i++){
        for (int j = 1; j <= s;j++){

            if(arr[i-1]<=j){
                dp[i][j] = dp[i-1][j]+dp[i][j - arr[i-1]];
            }
            else{

                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    return dp[n][s];
}
int main(){
    vector<int> arr = {1, 2, 3};
    cout << func(arr,3,4);
    return 0;
}