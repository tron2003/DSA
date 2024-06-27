#define mod 2000000000
class Solution
{
public:
    int helper(vector<vector<int>> &grid)
    {

        int m = grid.size();
        int n = grid[0].size();

        vector<vector<long long>> dp(m + 1, vector<long long>(n + 1, 0));
        dp[0][0] = 1;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {

                if (grid[i][j] != 1)
                {

                    long up = 0;
                    long left = 0;
                    if (i > 0)
                    {
                        up = dp[i - 1][j];
                    }
                    if (j > 0)
                    {
                        left = dp[i][j - 1];
                    }
                    dp[i][j] += (up + left);
                }
                else
                {
                    dp[i][j] = 0;
                }
            }
        }
        return dp[m - 1][n - 1];
    }
    int uniquePathsWithObstacles(vector<vector<int>> &grid)
    {
        int res = helper(grid);
        return res;
    }
};