class Solution
{
public:
    long long helper(vector<int> &arr1, vector<int> &arr2, long long i, long long k,
                     vector<vector<long long>> &dp)
    {

        long long n = arr1.size();
        if (i == 0)
        {
            return k == 0 ? arr1[0] : arr2[0];
        }
        if (i < 0)
        {
            return 0;
        }
        if (dp[i][k] != -1)
        {
            return dp[i][k];
        }
        long long inc = 0;
        long long exe = 0;
        // int inc = arr1[i] + helper(arr1, arr2, i - 1, dp);
        if (k == 0)
        {
            inc = arr1[i] + helper(arr1, arr2, i - 1, k, dp);
            exe = helper(arr1, arr2, i - 1, 1, dp);
        }
        else
        {
            inc = arr2[i] + helper(arr1, arr2, i - 1, k, dp);
            exe = helper(arr1, arr2, i - 1, 0, dp);
        }

        // int exe = helper(arr2,arr1,i-1,dp);

        return dp[i][k] = max(inc, exe);
    }
    long long maxEnergyBoost(vector<int> &arr1, vector<int> &arr2)
    {

        int n = arr1.size();
        vector<vector<long long>> dp1(n + 1, vector<long long>(2, -1));
        vector<vector<long long>> dp2(n + 1, vector<long long>(2, -1));
        long long res = max(helper(arr1, arr2, n - 1, 0, dp1),
                            helper(arr1, arr2, n - 1, 1, dp2));

        return res;
    }
};