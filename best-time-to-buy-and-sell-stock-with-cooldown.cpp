class Solution
{
public:
    int helper(vector<int> &arr, int i, int buy, int cool,
               vector<vector<vector<int>>> &dp)
    {

        if (i >= arr.size())
        {
            return 0;
        }
        if (dp[i][buy][cool] != -1)
        {
            return dp[i][buy][cool];
        }
        int res = 0;
        if (buy && cool == 1)
        {

            res = max({res, -arr[i] + helper(arr, i + 1, 0, 1, dp),
                       0 + helper(arr, i + 1, 1, 1, dp)});
        }
        if (!buy)
        {
            res = max({res, arr[i] + helper(arr, i + 1, 1, 0, dp),
                       helper(arr, i + 1, 0, 1, dp)});
        }
        else if (buy && cool == 0)
        {
            res = helper(arr, i + 1, 1, 1, dp);
        }

        return dp[i][buy][cool] = res;
    }
    int maxProfit(vector<int> &arr)
    {

        int n = arr.size();
        vector<vector<vector<int>>> dp(
            n, vector<vector<int>>(3, vector<int>(3, -1)));
        int res = helper(arr, 0, 1, 1, dp);
        return res;
    }
};