#include <iostream>
#include <vector>
#include <bits/stdc++.h>
#include <algorithm>

using namespace std;

int helper(vector<vector<int>> arr, int i, int j, int &res)
{
    if (i >= arr.size() || j >= arr[0].size())
    {
        return 0;
    }
    int right = helper(arr, i + 1, j, res);
    int dia = helper(arr, i + 1, j + 1, res);
    int dow = helper(arr, i, j + 1, res);
    if (arr[i][j] == 1)
    {
        int ans = 1 + min({right, dia, dow});
        res = max(res, ans);
        return ans;
    }
    else{
        return 0;
    }
}
int helper_memo(vector<vector<int>> arr, int i, int j,int &res,vector<vector<int>>&dp )
{
    if (i >= arr.size() || j >= arr[0].size())
    {
        return 0;
    }
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    int right = helper_memo(arr, i + 1, j, res,dp);
    int dia = helper_memo(arr, i + 1, j + 1, res,dp);
    int dow = helper_memo(arr, i, j + 1, res,dp);
    if (arr[i][j] == 1)
    {
       dp[i][j] = 1 + min({right, dia, dow});
        res = max(res, dp[i][j]);
        return dp[i][j];
    }
    else{
        return 0;
    }
}

int helper_tab(vector<vector<int>> arr,int res,vector<vector<int>>&dp )
{

    int n = arr.size();

    for (int i = n - 1; i >= 0;i--){

        for (int j = n - 1; j >= 0;j--){
            int l = dp[i][j+1];
            int t = dp[i+1][j];
            int d = dp[i + 1][j + 1];
            if(arr[i][j]==1){

                dp[i][j] = 1 + min({l, t, d});
                res = max(res, dp[i][j]);
         
            }
            else{
                dp[i][j] = 0;
            }

        }
    }
    return dp[0][0];
}
int helper_sc(vector<vector<int>> arr,int res,vector<vector<int>>&dp )
{

    int n = arr.size();
    vector<int>curr(n + 1, 0);
    vector<int>next(n + 1, 0);
    for (int i = n - 1; i >= 0;i--){

        for (int j = n - 1; j >= 0;j--){
            int r = curr[j+1];
            int t = next[j];
            int d = next[j + 1];
            if(arr[i][j]==1){

               curr[j] = 1 + min({r, t, d});
                
                res = max(res, curr[j]);
         
            }
            else{
                curr[j] = 0;
            }

        }
        next = curr;
    }
    return next[0];
}



void func()
{
    // vector<int> cost = {2, 7, 20};
    vector<vector<int>> arr = {{1, 1}, {1, 1}};
    int n = arr.size();

    int res =0,res1;
    // vector<vector<int>> dp(n, vector<int>(n, -1));
    vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
    // res=helper(arr, 0, 0, res);
    // res=helper_memo(arr, n-1, n-1, res,dp);
    // res1=helper_tab(arr,  res,dp);
    res1=helper_sc(arr,  res,dp);

    cout << res1;
}

int main()
{
    func();
    return 0;
}
