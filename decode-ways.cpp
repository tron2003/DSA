class Solution
{
public:
    int helper(string s, int i, int n, vector<int> &dp)
    {

        if (i == n)
        {
            return 1;
        }
        if (s[i] == '0')
        {
            return 0;
        }
        if (i > n)
        {
            return 0;
        }
        if (i == n - 1)
        {
            return 1;
        }
        if (dp[i] != -1)
        {
            return dp[i];
        }
        string temp = s.substr(i, 2);
        int res1 = helper(s, i + 1, n, dp);
        int res2 = 0;
        if (stoi(temp) <= 26 && stoi(temp) > 0)
        {
            res2 = helper(s, i + 2, n, dp);
        }
        return dp[i] = res2 + res1;
    }
    int numDecodings(string s)
    {

        int n = s.size();
        vector<int> dp(n + 1, -1);
        int res = helper(s, 0, n, dp);

        return res;
    }
};