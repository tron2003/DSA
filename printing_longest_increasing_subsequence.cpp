class Solution
{
public:
    vector<int> longestIncreasingSubsequence(int n, vector<int> &arr)
    {
        if (n == 0)
            return {};

        vector<int> dp(n, 1);
        vector<int> prev(n, -1);

        int max_len = 1;
        int max_index = 0;

        // Fill dp array and prev array
        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (arr[i] > arr[j] && dp[i] < dp[j] + 1)
                {
                    dp[i] = dp[j] + 1;
                    prev[i] = j;
                }
            }
            // Update the maximum length and corresponding index
            if (dp[i] > max_len)
            {
                max_len = dp[i];
                max_index = i;
            }
        }

        // Backtrack to find the longest increasing subsequence
        vector<int> res;
        int idx = max_index;
        while (idx != -1)
        {
            res.push_back(arr[idx]);
            idx = prev[idx];
        }

        reverse(res.begin(), res.end());
        return res;
    }
};
