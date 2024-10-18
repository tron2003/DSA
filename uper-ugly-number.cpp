class Solution
{
public:
    int nthSuperUglyNumber(int n, vector<int> &arr)
    {

        unordered_map<int, int> mp;

        vector<long long> dp(n);
        dp[0] = 1;
        vector<long long> idx(arr.size(), 0);
        vector<long long> next(arr.size());

        for (int i = 0; i < arr.size(); i++)
        {

            next[i] = arr[i];
        }
        for (int i = 1; i < n; i++)
        {
            int temp = *min_element(next.begin(), next.end());
            dp[i] = temp;
            for (int j = 0; j < arr.size(); j++)
            {
                if (dp[i] == next[j])
                {
                    idx[j]++;
                    next[j] = dp[idx[j]] * arr[j];
                }
            }
        }
        return dp[n - 1];
    }
};