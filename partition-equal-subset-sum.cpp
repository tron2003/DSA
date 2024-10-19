class Solution
{
public:
    bool helper(vector<int> &arr, int i, int sum, int tar, vector<vector<int>> &dp)
    {

        if (tar == sum)
        {
            return true;
        }

        if (i >= arr.size())
        {
            return false;
        }
        if (sum > tar)
        {
            return false;
        }
        if (dp[i][sum] != -1)
        {
            return dp[i][sum];
        }

        int inc = helper(arr, i + 1, sum + arr[i], tar, dp);
        int exe = helper(arr, i + 1, sum, tar, dp);
        return dp[i][sum] = inc || exe;
    }
    bool canPartition(vector<int> &arr)
    {

        int n = arr.size();
        int sum = 0;
        for (auto x : arr)
        {

            sum += x;
        }
        if (sum % 2 != 0)
        {

            return false;
        }
        int tar = sum / 2;
        vector<vector<int>> dp(n + 1, vector<int>(tar + 1, -1));
        return helper(arr, 0, 0, tar, dp);
    }
};