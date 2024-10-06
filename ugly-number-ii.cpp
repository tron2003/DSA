class Solution
{
public:
    int nthUglyNumber(int n)
    {
        int temp1 = 0;
        int temp2 = 0;
        int temp3 = 0;

        vector<int> dp(n);
        dp[0] = 1;
        // res.push_back(1);
        for (int i = 1; i < n; i++)
        {
            int two = dp[temp1] * 2;
            int three = dp[temp2] * 3;
            int five = dp[temp3] * 5;
            dp[i] = min({two, five, three});
            if (two == dp[i])
            {
                temp1++;
            }

            if (three == dp[i])
            {

                temp2++;
            }
            if (five == dp[i])
            {
                temp3++;
            }
        }
        return dp[n - 1];
    }
};