#include <vector>
#include <unordered_map>
#include <list>
#include <algorithm>
using namespace std;

class Solution
{
public:
    void dfs(unordered_map<int, list<int>> &mp, vector<vector<int>> &dp, int root, int parent)
    {
        for (auto n : mp[root])
        {
            if (n != parent)
            {
                dfs(mp, dp, n, root);
                int curr = dp[n][0] + (n % 2 == 1 ? 1 : 2);
                if (curr > dp[root][0])
                {
                    dp[root][1] = dp[root][0];
                    dp[root][0] = curr;
                }
                else if (curr > dp[root][1])
                {
                    dp[root][1] = curr;
                }
            }
        }
    }

    void helper(unordered_map<int, list<int>> &mp, vector<vector<int>> &dp, vector<int> &res, int root, int parent, int inc)
    {
        res[root] = max(dp[root][0], inc);
        int pa = (root % 2 == 1 ? 1 : 2);

        for (auto n : mp[root])
        {
            if (n != parent)
            {
                int curr = dp[n][0] + (n % 2 == 1 ? 1 : 2);
                int x = (curr == dp[root][0]) ? dp[root][1] : dp[root][0];
                helper(mp, dp, res, n, root, max(pa + inc, pa + x));
            }
        }
    }

    vector<int> timeTaken(vector<vector<int>> &arr)
    {
        if (arr.empty())
            return {};

        unordered_map<int, list<int>> mp;
        for (const auto &edge : arr)
        {
            int u = edge[0];
            int v = edge[1];
            mp[u].push_back(v);
            mp[v].push_back(u);
        }

        vector<vector<int>> dp(mp.size(), vector<int>(2, 0));
        vector<int> res(mp.size(), 0);

        dfs(mp, dp, arr[0][0], -1);
        helper(mp, dp, res, arr[0][0], -1, 0);

        return res;
    }
};
