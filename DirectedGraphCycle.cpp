class Solution
{
public:
    bool dfs(int parent, vector<int> adj[], vector<bool> &vis, vector<bool> &path)
    {
        path[parent] = true;
        vis[parent] = true;

        for (int n : adj[parent])
        {
            if (!vis[n])
            {
                if (dfs(n, adj, vis, path))
                {
                    return true;
                }
            }
            else if (path[n])
            {
                return true;
            }
        }

        path[parent] = false;
        return false;
    }

    bool isCyclic(int v, vector<int> adj[])
    {
        vector<bool> vis(v, false);
        vector<bool> path(v, false);

        for (int i = 0; i < v; i++)
        {
            if (!vis[i])
            {
                if (dfs(i, adj, vis, path))
                {
                    return true;
                }
            }
        }

        return false;
    }
};
