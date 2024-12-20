class Solution
{
public:
    int ans = INT_MAX;
    void helper(int i, vector<int> &arr, int k, vector<int> &dp)
    {

        if (i >= arr.size())
        {

            int temp = INT_MIN;
            for (auto x : dp)
            {

                temp = max(x, temp);
            }
            ans = min(ans, temp);
            return;
        }

        for (int j = 0; j < k; j++)
        {

            dp[j] += arr[i];
            helper(i + 1, arr, k, dp);
            dp[j] -= arr[i];
        }
    }
    int distributeCookies(vector<int> &arr, int k)
    {

        int n = arr.size();
        int sum = 0;
        vector<int> dp(k, 0);
        helper(0, arr, k, dp);
        return ans;
    }
};