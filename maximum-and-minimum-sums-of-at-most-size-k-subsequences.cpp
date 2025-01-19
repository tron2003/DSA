class Solution
{
public:
    int minMaxSums(vector<int> &arr, int k)
    {

        sort(arr.begin(), arr.end());
        int res = 0;
        int mod = 1e9 + 7;
        vector<vector<int>> dp(arr.size() + 1, vector<int>(k + 1, 0));

        dp[0][0] = 1;
        for (int n = 1; n <= arr.size(); n++)
        {

            dp[n][0] = 1;
            for (int r = 1; r <= k; r++)
            {

                dp[n][r] = (dp[n - 1][r - 1] + dp[n - 1][r]) % mod;
            }
        }
        for (int n = 0; n < arr.size(); n++)
        {
            int z = 0;
            for (int r = 0; r <= k - 1; r++)
            {
                if (n >= r)
                {
                    z = (z + dp[n][r]) % mod;
                }
            }
            res =
                (res + (long long)(arr[n] + arr[arr.size() - n - 1]) * z) % mod;
        }
        return res;
    }
};