class Solution
{
public:
    int helper(int i, int j, int m, int n, vector<vector<int>> &dp)
    {

        if (i == m - 1 && j == n - 1)
        {

            return 1;
        }
        if (i >= m || j >= n)
        {

            return 0;
        }
        if (dp[i][j] != -1)
        {
            return dp[i][j];
        }

        int right = helper(i + 1, j, m, n, dp);
        int down = helper(i, j + 1, m, n, dp);
        return dp[i][j] = right + down;
    }
    int uniquePaths(int m, int n)
    {

        vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));
        int res = helper(0, 0, m, n, dp);

        return res;
    }
};