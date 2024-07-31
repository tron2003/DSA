class Solution
{
public:
    bool check(int start, int n, unordered_map<int, vector<int>> &adj,
               vector<int> &vis)
    {

        queue<int> que;
        que.push(start);

        vis[start] = 0;
        while (!que.empty())
        {

            int temp = que.front();
            que.pop();

            for (auto n : adj[temp])
            {

                if (vis[n] == -1)
                {
                    vis[n] = !vis[temp];
                    que.push(n);
                }
                else if (vis[n] == vis[temp])
                {
                    return false;
                }
            }
        }
        return true;
    }
    bool dfs(int start, int color, unordered_map<int, vector<int>> &adj,
             vector<int> &vis)
    {
        vis[start] = color;
        for (auto n : adj[start])
        {
            if (vis[n] == -1)
            {
                if (dfs(n, !color, adj, vis) == false)
                {
                    return false;
                }
            }
            else if (vis[n] == color)
            {
                return false;
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>> &arr)
    {
        int n = arr.size();
        vector<int> vis(n, -1);
        unordered_map<int, vector<int>> adj;
        queue<int> que;
        for (int i = 0; i < n; i++)
        {

            int k = arr[i].size();
            for (int j = 0; j < k; j++)
            {
                adj[i].push_back(arr[i][j]);
                adj[arr[i][j]].push_back(i);
            }
        }

        for (int i = 0; i < n; i++)
        {
            if (vis[i] == -1)
            {

                if (!dfs(i, 0, adj, vis))
                {

                    return false;
                }
            }
        }

        return true;
    }
};