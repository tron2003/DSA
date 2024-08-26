class Solution
{
public:
    int helper(int i, int prev, int half, int n, int k, vector<int> &power,
               vector<int> &res, vector<vector<int>> &dp)
    {
        if (i == half)
        {
            return prev == 0;
        }
        if (dp[i][prev] != -1)
        {
            return dp[i][prev];
        }
        for (int d = 9; d >= 0; d--)
        {

            int newmod = prev;
            if ((n & 1) && (i == half - 1))
            {

                newmod += (d * power[i]) % k;
            }
            else
            {
                newmod += (d * power[i]) % k;
                newmod += (d * power[n - i - 1]) % k;
            }
            newmod = newmod % k;
            int flag = helper(i + 1, newmod, half, n, k, power, res, dp);
            if (flag)
            {
                res[i] = d;
                break;
            }
        }
        if (res[i] == -1)
        {
            return dp[i][prev] = 0;
        }
        return dp[i][prev] = 1;
    }
    string largestPalindrome(int n, int k)
    {
        int half = (n + 1) / 2;
        vector<int> power(n, 0);
        power[0] = 1 % k;
        for (int i = 1; i < n; i++)
        {
            power[i] = (power[i - 1] * 10) % k;
        }
        vector<int> res(n, -1);
        vector<vector<int>> dp(half, vector<int>(k, -1));
        int prev = 0;
        helper(0, prev, half, n, k, power, res, dp);
        string temp(n, '0');
        for (int i = 0; i < half; i++)
        {

            temp[i] = '0' + res[i];
            temp[n - i - 1] = temp[i];
        }
        return temp;
    }
};