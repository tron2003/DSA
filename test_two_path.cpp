class Solution
{
public:
    // int helper(vector<vector<int>> matrix, vector<vector<int>>& dp, int i,
    //            int j) {
    //     int m = matrix.size();
    //     int n = matrix[0].size();
    //     if (j < 0 || j >= n) {
    //         return 1e8;
    //     }
    //     if (i == 0) {
    //         return matrix[0][j];
    //     }
    //     if (dp[i][j] != -1) {
    //         return dp[i][j];
    //     }
    //     long long left = matrix[i][j] + helper(matrix, dp, i - 1, j - 1);
    //     long long right = matrix[i][j] + helper(matrix, dp, i - 1, j + 1);
    //     long long up = matrix[i][j] + helper(matrix, dp, i - 1, j);
    //     return dp[i][j] = min({left, right, up});
    // }
    int helper(vector<vector<int>> matrix)
    {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<long long>> dp(m + 1, vector<long long>(n + 1, 1e7));
        vector<int> prev(n + 1, 1e7);
        vector<int> curr(n + 1, 1e7);
        for (int i = 0; i < n; i++)
        {
            prev[i] = matrix[0][i];
        }
        for (int i = 1; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {

                long long left = 1e7;
                if (j - 1 >= 0)
                {
                    // left = 1e7;
                    left = matrix[i][j] + prev[j - 1];
                }
                long long right = 1e7;
                if (j + 1 < n)
                {
                    right = matrix[i][j] + prev[j + 1];
                    // right = 1e7;
                }
                long long up = matrix[i][j] + prev[j];
                curr[j] = min({left, right, up});
            }
            prev = curr;
        }
        int res = 1e7;
        for (int i = 0; i < n; i++)
        {
            res = min(res, (int)prev[i]);
        }
        return res;
    }
    int minFallingPathSum(vector<vector<int>> &matrix)
    {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));
        int res;

        res = helper(matrix);

        return res;
    }
};