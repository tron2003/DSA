class Solution
{
public:
    int helper(vector<vector<int>> &arr, int i, int j,
               vector<vector<long long>> &dp)
    {

        if (dp[i][j] != -1)
        {
            return dp[i][j];
        }
        int left = 1;
        int m = arr.size();
        int n = arr[i].size();
        int num = arr[i][j];
        if (j - 1 >= 0)
        {
            if (arr[i][j - 1] > num)
            {
                left += helper(arr, i, j - 1, dp);
            }
        }
        int right = 1;
        if (j + 1 < arr[i].size())
        {

            if (arr[i][j + 1] > num)
            {

                right += helper(arr, i, j + 1, dp);
            }
        }
        int up = 1;
        if (i - 1 >= 0)
        {
            if (arr[i - 1][j] > num)
            {
                up += helper(arr, i - 1, j, dp);
            }
        }
        int down = 1;
        if (i + 1 <= arr.size() - 1)
        {
            if (arr[i + 1][j] > num)
            {
                down += helper(arr, i + 1, j, dp);
            }
        }
        return dp[i][j] = max({left, right, up, down});
    }
    int longestIncreasingPath(vector<vector<int>> &arr)
    {
        int m = arr.size();
        int n = arr[0].size();
        int res = 0;
        vector<vector<long long>> dp(m, vector<long long>(n, -1));
        for (int i = 0; i < m; i++)
        {

            for (int j = 0; j < n; j++)
            {
                res = max(res, helper(arr, i, j, dp));
            }
        }
        return res;
    }
};