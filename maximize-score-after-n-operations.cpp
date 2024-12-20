class Solution
{
public:
    int gcd(int x, int y)
    {

        if (x == 0)
        {

            return y;
        }
        return gcd(y % x, x);
    }
    int helper(int op, int i, vector<int> &arr, vector<int> &dp)
    {
        int m = arr.size();
        int n = arr.size() / 2;
        if (op > n)
        {
            return 0;
        }
        if (dp[i] != -1)
        {
            return dp[i];
        }
        dp[i] = 0;
        for (int j = 0; j < m; j++)
        {
            if ((i & (1 << j)))
            {
                continue;
            }
            for (int k = j + 1; k < m; k++)
            {
                if ((i & (1 << k)))
                {
                    continue;
                }
                int newi = (1 << j) | (1 << k) | i;
                int currentGCD = gcd(arr[j], arr[k]);
                int res = op * currentGCD + helper(op + 1, newi, arr, dp);
                dp[i] = max(dp[i], res);
            }
        }
        return dp[i];
    }
    int maxScore(vector<int> &arr)
    {
        int m = arr.size();
        int n = arr.size() / 2;
        vector<int> dp(1 << m, -1);

        int res = helper(1, 0, arr, dp);
        return res;
    }
};