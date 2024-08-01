class Solution
{
public:
    void dfs(int node, unordered_map<int, list<pair<int, int>>> &mp, vector<int> &vis, stack<int> &st)
    {

        vis[node] = 1;
        for (auto n : mp[node])
        {
            auto temp = n.first;
            if (!vis[temp])
            {
                dfs(temp, mp, vis, st);
            }
        }
        st.push(node);
    }
    vector<int> shortestPath(int n, int m, vector<vector<int>> &arr)
    {
        // code here
        unordered_map<int, list<pair<int, int>>> mp;
        vector<int> vis(n, 0);
        for (int i = 0; i < m; i++)
        {

            int u = arr[i][0];
            int v = arr[i][1];
            int w = arr[i][2];
            mp[u].push_back({v, w});
        }
        stack<int> st;
        for (int i = 0; i < n; i++)
        {

            if (!vis[i])
            {
                dfs(i, mp, vis, st);
            }
        }
        vector<int> res(n, 1e9);
        res[0] = 0;
        while (!st.empty())
        {
            auto temp = st.top();
            st.pop();
            if (res[temp] != INT_MAX)
            {
                for (auto n : mp[temp])
                {
                    int u = temp;
                    int v = n.first;
                    int w = n.second;
                    if (res[u] + w < res[v])
                    {
                        res[v] = res[u] + w;
                    }
                }
            }
        }
        for (int i = 0; i < n; i++)
        {
            if (res[i] == 1e9)
            {
                res[i] = -1;
            }
        }
        return res;
    }
};
