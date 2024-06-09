#include <iostream>
#include <vector>
#include <bits/stdc++.h>
#include <algorithm>

using namespace std;

int helper(vector<int> arr, vector<int> cost, int n, int i)
{
    if (i >= n)
    {
        return 0;
    }
    int cost1 = cost[0] + helper(arr, cost, n, i + 1);

    int j = 0;
    for (j = i; j < n && arr[j] < arr[i] + 7; j++)
        ;
    int cost2 = cost[1] + helper(arr, cost, n, j);

    for (j = i; j < n && arr[j] < arr[i] + 30; j++)
        ;
    int cost3 = cost[2] + helper(arr, cost, n, j);

    return min({cost1, cost2, cost3});
}

int helper_memo(vector<int> arr, vector<int> cost, int n, int i, vector<int> &dp)
{
    if (i >= n)
    {
        return 0;
    }
    if (dp[i] != -1)
    {
        return dp[i];
    }
    int cost1 = cost[0] + helper_memo(arr, cost, n, i + 1, dp);

    int j = 0;
    for (j = i; j < n && arr[j] < arr[i] + 7; j++)
        ;
    int cost2 = cost[1] + helper_memo(arr, cost, n, j, dp);

    for (j = i; j < n && arr[j] < arr[i] + 30; j++)
        ;
    int cost3 = cost[2] + helper_memo(arr, cost, n, j, dp);

    dp[i] = min({cost1, cost2, cost3});
    return dp[i];
}

int helper_tab(vector<int> arr, vector<int> cost, int n, int i)
{

    vector<int> dp(n + 1, 100000000);
    dp[n] = 0;

    for (int k = n - 1; k >= 0; k--)
    {
        int cost1 = cost[0] + dp[k + 1];

        int j = 0;
        for (j = k; j < n && arr[j] < arr[k] + 7; j++)
            ;
        int cost2 = cost[1] + dp[j];

        for (j = k; j < n && arr[j] < arr[k] + 30; j++)
            ;
        int cost3 = cost[2] + dp[j];

        dp[k] = min({cost1, cost2, cost3});
    }

    return dp[0];
}

int helper_que(vector<int> arr, vector<int> cost, int n, int i)
{

    int ans =0;

    queue<pair<int, int>> week;
    queue<pair<int, int>> month;
    for (auto x : arr)
    {

        while (!week.empty() && week.front().first + 7 <= x)
        {
            week.pop();
        }
        while (!month.empty() && month.front().first + 30 <= x)
        {
            month.pop();
        }

        week.push({x, ans + cost[1]});
        month.push({x, ans + cost[2]});

        ans = min({ans+cost[0],week.front().second,month.front().second});
    }
    return ans;
}

void func()
{
    vector<int> cost = {2, 7, 20};
    vector<int> arr = {1, 3, 4, 5, 7, 8, 10};
    int n = arr.size();

    vector<int> dp(n + 1, -1);
    // int res = helper_memo(arr, cost, n, 0, dp);
    // int res = helper_tab(arr, cost, n, 0);
    int res = helper_que(arr, cost, n, 0);
    cout << res;
}

int main()
{
    func();
    return 0;
}
