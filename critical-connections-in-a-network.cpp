class Solution
{
public:
    int timer = 1;
    void dfs(int node, int parent, unordered_map<int, list<int>> &mp, vector<int> &vis,
             vector<int> &low, vector<int> &first, vector<vector<int>> &res)
    {

        vis[node] = 1;
        low[node] = first[node] = timer;
        timer++;
        for (auto n : mp[node])
        {

            if (n == parent)
            {
                continue;
            }
            if (!vis[n])
            {

                dfs(n, node, mp, vis, low, first, res);
                low[node] = min(low[node], low[n]);
                if (low[n] > first[node])
                {

                    res.push_back({n, node});
                }
            }
            else
            {
                low[node] = min(low[node], low[n]);
            }
        }
    }

    vector<vector<int>> criticalConnections(int n, vector<vector<int>> &arr)
    {
        vector<int> vis(n, 0);
        vector<vector<int>> res;
        unordered_map<int, list<int>> mp;
        for (auto it : arr)
        {
            int u = it[0];
            int v = it[1];
            mp[u].push_back(v);
            mp[v].push_back(u);
        }
        // vector<int> vis(n, 0);
        vector<int> low(n, 0);
        vector<int> first(n, 0);
        dfs(0, -1, mp, vis, low, first, res);
        return res;
    }
};