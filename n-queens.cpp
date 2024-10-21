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
    void helper(int i, int n, vector<vector<int>> &dp,
                vector<vector<string>> &res, vector<string> &temp)
    {

        if (i == n)
        {
            res.push_back(temp);
            return;
        }
        string num = "";
        for (int k = 0; k < n; k++)
        {
            num += ".";
        }

        for (int j = 0; j < n; j++)
        {
            num[j] = 'Q';
            dp[i][j] = 1;

            if (check(i, j, dp))
            {
                temp.push_back(num);
                helper(i + 1, n, dp, res, temp);
                temp.pop_back()
            }
            num[j] = '.';
            dp[i][j] = 0;
        }
    }
    vector<vector<string>> solveNQueens(int n)
    {

        vector<vector<int>> dp(n, vector<int>(n, 0));
        vector<string> temp;
        vector<vector<string>> res;
        helper(0, n, dp, res, temp);

        return res;
    }
};