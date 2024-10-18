class Solution
{
public:
    int helper(int n, vector<int> &dp)
    {

        if (n <= 2)
        {

            return 1;
        }
        if (dp[n] != -1)
        {
            return dp[n];
        }
        int res = 0;
        for (int i = 2; i < n; i++)
        {

            res = max(res, max(i * helper(n - i, dp), i * (n - i)));
        }

        return dp[n] = res;
    }
    int integerBreak(int n)
    {
        if (n == 2)
        {
            return 1;
        }
        vector<int> dp(n + 1, -1);
        int res = helper(n, dp);

        return res;
    }
};