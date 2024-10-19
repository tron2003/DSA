class Solution
{
public:
    vector<int> check(string s)
    {

        int i = 0;
        int j = 0;
        for (auto x : s)
        {

            if (x == '0')
            {
                i++;
            }
            else
            {
                j++;
            }
        }
        return {i, j};
    }
    int helper(vector<string> &arr, int i, int sum1, int sum2, int m, int n,
               vector<vector<vector<int>>> &dp)
    {

        if ((sum1 >= m && sum2 >= n))
        {
            return 0;
        }
        if (i >= arr.size())
        {
            return 0;
        }
        if (dp[i][sum1][sum2] != -1)
        {
            return dp[i][sum1][sum2];
        }
        vector<int> arr2 = check(arr[i]);
        int temp1 = arr2[0];
        int temp2 = arr2[1];
        int res = INT_MIN;
        if ((sum1 + temp1 <= m) && (temp2 + sum2 <= n))
        {

            res = max(res,
                      1 + helper(arr, i + 1, sum1 + temp1, sum2 + temp2, m, n, dp));
        }
        res = max(helper(arr, i + 1, sum1, sum2, m, n, dp), res);

        return dp[i][sum1][sum2] = res;
    }
    int findMaxForm(vector<string> &arr, int m, int n)
    {

        vector<vector<vector<int>>> dp(
            arr.size() + 1, vector<vector<int>>(m + 1, vector<int>(n + 1, -1)));
        int res = helper(arr, 0, 0, 0, m, n, dp);
        return res;
    }
};