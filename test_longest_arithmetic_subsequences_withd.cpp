#include <iostream>
#include <vector>
#include <bits/stdc++.h>
#include <algorithm>

using namespace std;

int helper(int idx, int diff, vector<int> arr1)

{
    if (idx < 0)
    {
        return 0;
    }
    int ans = 0;
    for (int i = idx - 1; i >= 0; i--)
    {
        if (arr1[idx] - arr1[i] == diff)
        {
            ans = max(ans, 1 + helper(i, diff, arr1));
        }
    }
    return ans;
}

int helper_memo(int idx, int diff, vector<int> arr, unordered_map<int, int> &dp)

{

    if (idx < 0)
    {
        return 0;
    }
    if (dp[idx])
    {

        return dp[idx];
    }
    int ans = 0;
    for (int i = idx - 1; i >= 0; i--)
    {
        if (arr[idx] - arr[i] == diff)
        {
            ans = max(ans, 1 + helper_memo(i, diff, arr, dp));
        }
    }
    dp[idx] = ans;
    return dp[idx];
}

int helper_tab(vector<int> &arr, int n, int diff)
{
    int ans = 0;
  unordered_map<int, int>dp(n);
    for (int i = 0; i < n; i++)
    {
        int temp = arr[i] - diff;
        int count = 0;
        if (dp.find(temp) != dp.end())
        {
            count = dp[temp];
        }
        dp[arr[i]] = 1+count;
        ans = max(ans, dp[arr[i]]);
    }
    return ans;
}

int helper_sc(vector<int> &arr1, vector<int> &arr2, int idx, bool swap1)
{
}

void func()
{
    vector<int> arr = {1, 2, 5, 7};
    int n = arr.size();
    int ans = 0;
    if (n <= 2)
    {
        cout << n << " ";
        return; 
    }
    // for (int i = 0; i < n;i++){
    //     for (int j = i + 1; j < n;j++){
    //         ans = max(ans, 2 + helper(i, arr1[j] - arr1[i],  arr1));
    //     }
    // }

    //    unordered_map<int,int>dp;

    //     for(int i =0;i<n;i++){
    //         for(int j =i+1;j<n;j++){
    //              ans = max(ans, 2 + helper_memo(i, arr1[j] - arr1[i],  arr1,dp));
    //         }
    //     }
    int diff = 1;
    ans = helper_tab(arr, n, diff);
    cout << ans;
}

int main()
{
    func();
    return 0;
}
