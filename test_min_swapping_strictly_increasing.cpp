#include <iostream>
#include <vector>
#include <bits/stdc++.h>
#include <algorithm>

using namespace std;

int helper(vector<int> &arr1, vector<int> &arr2, int idx, bool swap1)

{
    if (idx >= arr1.size())
    {
        return 0;
    }

    int prev1 = arr1[idx - 1];
    int prev2 = arr2[idx - 1];
    if (swap1)
    {
        swap(prev1, prev2);
    }
    // not swapping
    int ans = INT_MAX;
    if (arr1[idx] > prev1 && arr2[idx] > prev2)
    {
        ans = helper(arr1, arr2, idx + 1, 0);
    }

    // swapping need
    if (arr1[idx] > prev2 && arr2[idx] > prev1)
    {

        ans = min(ans, 1 + helper(arr1, arr2, idx + 1, 1));
    }
    return ans;
}

int helper_memo(vector<int> &arr1, vector<int> &arr2, int idx, bool swap1, vector<vector<int>> &dp)

{
    if (idx >= arr1.size())
    {
        return 0;
    }
    if (dp[idx][swap1] != -1)
    {
        return dp[idx][swap1];
    }
    int prev1 = arr1[idx - 1];
    int prev2 = arr2[idx - 1];
    if (swap1)
    {
        swap(prev1, prev2);
    }
    // not swapping
    int ans = INT_MAX;
    if (arr1[idx] > prev1 && arr2[idx] > prev2)
    {
        ans = helper_memo(arr1, arr2, idx + 1, 0, dp);
    }

    // swapping need
    if (arr1[idx] > prev2 && arr2[idx] > prev1)
    {

        ans = min(ans, 1 + helper_memo(arr1, arr2, idx + 1, 1, dp));
    }
    dp[idx][swap1] = ans;
    return dp[idx][swap1];
}

bool helper_tab(vector<int> &arr1, vector<int> &arr2, int idx, bool swap1)
{
    int n = arr1.size();
    vector<vector<int>> dp(n + 1, vector<int>(2, 0));
    dp[n][0] = 0;
    dp[n][1] = 0;
    for (int idx = n - 1; idx >= 1; idx--)
    {

        for (int swap1 = 1; swap1 >= 0; swap1--)
        {
            int prev1 = arr1[idx - 1];
            int prev2 = arr2[idx - 1];
            if (swap1)
            {
                swap(prev1, prev2);
            }
            // not swapping
            int ans = INT_MAX;
            if (arr1[idx] > prev1 && arr2[idx] > prev2)
            {
                ans = dp[idx + 1][0];
            }

            // swapping need
            if (arr1[idx] > prev2 && arr2[idx] > prev1)
            {

                ans = min(ans, 1 + dp[idx + 1][1]);
            }
            dp[idx][swap1] = ans;
        }
    }
    return dp[1][0];
}

int helper_sc(vector<int> &arr1, vector<int> &arr2, int idx, bool swap1)
{

    int n = arr1.size();
    vector<vector<int>> dp(n + 1, vector<int>(2, 0));
    int col1 = 0; // not swapping
    int currswap = 0;
    int currnoswap = 0;
    int col2 = 0; // swapping
    for (int idx = n - 1; idx >= 1; idx--)
    {

        for (int swap1 = 1; swap1 >= 0; swap1--)
        {
            int prev1 = arr1[idx - 1];
            int prev2 = arr2[idx - 1];
            if (swap1)
            {
                swap(prev1, prev2);
            }
            // not swapping
            int ans = INT_MAX;
            if (arr1[idx] > prev1 && arr2[idx] > prev2)
            {
                ans = col1;
            }

            // swapping need
            if (arr1[idx] > prev2 && arr2[idx] > prev1)
            {

                ans = min(ans, 1 + col2);
            }
            if (swap1)
            {

                currswap = ans;
            }
            else
            {
                currnoswap = ans;
            }
        }
        col2 = currswap;
        col1 = currnoswap;
        // col2 = col1;
    }
    return min(col1, col2);
}

void func()
{
    vector<int> arr1 = {1, 3, 7, 7};
    vector<int> arr2 = {2, 4, 6, 8};
    arr1.insert(arr1.begin(), -1);
    arr2.insert(arr2.begin(), -1);
    bool swap1 = 0;
    int n = arr1.size();
    vector<vector<int>> dp(n + 1, vector<int>(2, -1));
    // int res1 = helper(arr1, arr2, 1, swap1);
    // int res1 = helper_memo(arr1, arr2, 1, swap1, dp);
    // int res1 = helper_tab(arr1, arr2, 1, swap1);
    int res1 = helper_sc(arr1, arr2, 1, swap1);
    // long long res1 = helper_tab(arr, 0, half);
    // long long res1 = helper_sc(arr, 0, half);
    cout << res1 << " ";
}

int main()
{
    func();
    return 0;
}
