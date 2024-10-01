#define mod 1000000007
#define ll long long
class Solution
{
public:
    int maxProductPath(vector<vector<int>> &grid)
    {

        int m = grid.size();
        int n = grid[0].size();
        vector<vector<pair<ll, ll>>> dp(m, vector<pair<ll, ll>>(n));
        dp[0][0] = {grid[0][0], grid[0][0]};

        for (int i = 1; i < m; i++)
        {

            int val = dp[i - 1][0].first * grid[i][0];
            dp[i][0] = {val, val};
        }
        for (int i = 1; i < m; i++)
        {

            int val = dp[i - 1][0].first * grid[i][0];
            dp[i][0] = {val, val};
        }
        for (int j = 1; j < n; j++)
        {

            int val = dp[0][j - 1].first * grid[0][j];
            dp[0][j] = {val, val};
        }

        for (int i = 1; i < m; i++)
        {

            for (int j = 1; j < n; j++)
            {

                int val = grid[i][j];
                ll d1 = dp[i - 1][j].first * val;
                ll d2 = dp[i - 1][j].second * val;
                ll r1 = dp[i][j - 1].second * val;
                ll r2 = dp[i][j - 1].first * val;

                dp[i][j] = {max({d1, d2, r1, r2}), min({d1, d2, r1, r2})};
            }
        }

        int res = dp[m - 1][n - 1].first % mod;

        if (res < 0)
        {
            return -1;
        }
        return res;
    }
};