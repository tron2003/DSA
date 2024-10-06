class Solution
{
public:
    int helper(vector<vector<char>> &arr, int i, int j, int &res, vector<vector<int>> &dp)
    {

        if (i >= arr.size() || j >= arr[0].size())
        {
            return 0;
        }
        if (dp[i][j] != -1)
        {
            return dp[i][j];
        }
        int left = helper(arr, i + 1, j, res, dp);
        int right = helper(arr, i, j + 1, res, dp);
        int dia = helper(arr, i + 1, j + 1, res, dp);

        if (arr[i][j] == '1')
        {
            int temp = min({dia, left, right}) + 1;
            res = max(res, temp);
            return dp[i][j] = temp;
        }
        else
        {
            return 0;
        }
    }
    int maximalSquare(vector<vector<char>> &arr)
    {

        int res = 0;
        vector<vector<int>> dp(arr.size() + 1, vector<int>(arr[0].size() + 1, -1));
        helper(arr, 0, 0, res, dp);
        return res * res;
    }
};