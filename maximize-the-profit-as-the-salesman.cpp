class Solution
{
public:
    static bool cmp(vector<int> &a, vector<int> &b) { return a[1] < b[1]; }

    int maximizeTheProfit(int n, vector<vector<int>> &arr)
    {
        int k = arr.size();

        sort(arr.begin(), arr.end(), cmp);
        vector<int> dp(k, 0);
        dp[0] = arr[0][2];
        for (int i = 1; i < k; i++)
        {

            int temp = arr[i][2];
            int low = 0;
            int high = i - 1;
            int l = -1;
            while (low <= high)
            {
                int mid = low + (high - low) / 2;
                if (arr[mid][1] < arr[i][0])
                {

                    l = mid;
                    low = mid + 1;
                }
                else
                {

                    high = mid - 1;
                }
            }
            if (l != -1)
            {

                temp += dp[l];
            }
            dp[i] = max(dp[i - 1], temp);
        }
        return dp[k - 1];
    }
};