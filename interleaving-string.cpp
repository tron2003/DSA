class Solution
{
public:
    bool helper(string s1, string s2, string s3, string temp, int i, int j, vector<vector<int>> &dp)
    {

        if (i + j == s3.size())
        {
            return true;
        }

        if (i >= s1.size() && j >= s2.size())
        {

            return false;
        }
        if (dp[i][j] != -1)
        {
            return dp[i][j];
        }
        int res1 = 0;
        if (s1[i] == s3[i + j])
        {
            res1 = res1 | helper(s1, s2, s3, temp, i + 1, j, dp);
        }

        if (s2[j] == s3[i + j])
        {
            res1 = res1 | helper(s1, s2, s3, temp, i, j + 1, dp);
        }

        return dp[i][j] = res1;
    }
    bool isInterleave(string s1, string s2, string s3)
    {

        string temp;
        vector<vector<int>> dp(s1.size() + 1, vector<int>(s2.size() + 1, -1));

        if ((s1.size() + s2.size()) != s3.size())
        {
            return false;
        }
        int res = helper(s1, s2, s3, temp, 0, 0, dp);

        return res;
    }
};