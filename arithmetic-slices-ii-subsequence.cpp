class Solution
{
public:
    int numberOfArithmeticSlices(vector<int> &arr)
    {
        int n = arr.size();
        if (n < 3)
        {
            return 0;
        }
        vector<unordered_map<int, int>> dp(n);
        int res = 0;
        for (int i = 1; i < n; i++)
        {

            for (int j = 0; j < i; ++j)
            {

                long long diff = (long long)arr[i] - arr[j];

                if (diff < INT_MIN || diff > INT_MAX)
                {
                    continue;
                }
                int d = (int)diff;
                dp[i][d]++;
                if (dp[j].count(d))
                {

                    dp[i][d] += dp[j][d];
                    res += dp[j][d];
                }
            }
        }
        return res;
    }
};