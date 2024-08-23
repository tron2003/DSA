#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pa pair<ll, ll>

class Solution
{
public:
    ll helper(vector<vector<pa>> &arr, vector<vector<vector<ll>>> &dp, int idx, int col1, int col2, int rooks)
    {
        if (idx >= arr.size())
        {
            return rooks == 3 ? 0 : -1e18;
        }
        if (dp[idx][col1 + 1][col2 + 1] != -1)
        {
            return dp[idx][col1 + 1][col2 + 1];
        }

        ll res = -1e18;
        if (col1 == -1)
        {
            res = max(res, helper(arr, dp, idx + 1, col1, col2, rooks)); // Not take case
            res = max(res, arr[idx][0].first + helper(arr, dp, idx + 1, arr[idx][0].second, col2, rooks + 1));
            res = max(res, arr[idx][1].first + helper(arr, dp, idx + 1, arr[idx][1].second, col2, rooks + 1));
            res = max(res, arr[idx][2].first + helper(arr, dp, idx + 1, arr[idx][2].second, col2, rooks + 1));
        }
        else if (col2 == -1)
        {
            res = max(res, helper(arr, dp, idx + 1, col1, col2, rooks)); // Not take case
            if (arr[idx][0].second != col1)
            {
                res = max(res, arr[idx][0].first + helper(arr, dp, idx + 1, col1, arr[idx][0].second, rooks + 1));
            }
            if (arr[idx][1].second != col1)
            {
                res = max(res, arr[idx][1].first + helper(arr, dp, idx + 1, col1, arr[idx][1].second, rooks + 1));
            }
            if (arr[idx][2].second != col1)
            {
                res = max(res, arr[idx][2].first + helper(arr, dp, idx + 1, col1, arr[idx][2].second, rooks + 1));
            }
        }
        else
        {
            res = max(res, helper(arr, dp, idx + 1, col1, col2, rooks)); // Not take case
            if (arr[idx][0].second != col1 && arr[idx][0].second != col2)
            {
                res = max(res, arr[idx][0].first);
            }
            if (arr[idx][1].second != col1 && arr[idx][1].second != col2)
            {
                res = max(res, arr[idx][1].first);
            }
            if (arr[idx][2].second != col1 && arr[idx][2].second != col2)
            {
                res = max(res, arr[idx][2].first);
            }
        }

        return dp[idx][col1 + 1][col2 + 1] = res;
    }

    ll maximumValueSum(vector<vector<int>> &board)
    {
        int m = board.size();
        int n = board[0].size();
        vector<vector<pa>> arr(m);

        for (int i = 0; i < m; i++)
        {
            vector<pa> temp;
            for (int j = 0; j < n; j++)
            {
                temp.push_back({board[i][j], j});
            }
            sort(temp.rbegin(), temp.rend());
            while (temp.size() > 3)
                temp.pop_back();
            arr[i] = temp;
        }

        vector<vector<vector<ll>>> dp(m, vector<vector<ll>>(n + 1, vector<ll>(n + 1, -1)));
        ll res = helper(arr, dp, 0, -1, -1, 0);
        return res;
    }
};
