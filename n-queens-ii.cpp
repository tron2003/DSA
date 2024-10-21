

class Solution
{
public:
    bool check(int i, int j, vector<vector<int>> &dp)
    {

        int n = dp.size();
        for (int k = 0; k < n; k++)
        {
            if (dp[k][j] == 1 && k != i)
            {

                return false;
            }
        }

        int k = i - 1;
        int l = j - 1;
        while (k >= 0 && l >= 0)
        {

            if (dp[k][l] == 1)
            {
                return false;
            }
            k--;
            l--;
        }
        k = i - 1;
        l = j + 1;
        while (k >= 0 && l <= n - 1)
        {

            if (dp[k][l] == 1)
            {
                return false;
            }
            k--;
            l++;
        }

        return true;
    }
    void helper(int i, int n, vector<vector<int>> &dp, int &res)
    {

        if (i == n)
        {
            res++;
            return;
        }

        for (int j = 0; j < n; j++)
        {

            dp[i][j] = 1;

            if (check(i, j, dp))
            {

                helper(i + 1, n, dp, res);
            }

            dp[i][j] = 0;
        }
    }
    int totalNQueens(int n)
    {
        vector<vector<int>> dp(n, vector<int>(n, 0));
        int res = 0;
        helper(0, n, dp, res);

        return res;
    }
};