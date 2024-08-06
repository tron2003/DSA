class Solution
{
public:
    void dfs(unordered_map<int, list<int>> &mp, vector<bool> &vis, int i)
    {

        vis[i] = true;
        for (auto n : mp[i])
        {

            if (!vis[n])
            {
                dfs(mp, vis, n);
            }
        }
    }
    void unionbysize(vector<int> &rankbysize, vector<int> &parent, int u,
                     int v)
    {

        int u_parent = find(rankbysize, parent, u);
        int v_parent = find(rankbysize, parent, v);
        if (u_parent == v_parent)
        {
            return;
        }
        if (rankbysize[u_parent] > rankbysize[v_parent])
        {

            rankbysize[u_parent] += rankbysize[v_parent];
            parent[v_parent] = u_parent;
        }
        else
        {
            rankbysize[v_parent] += rankbysize[u_parent];
            parent[u_parent] = v_parent;
        }
    }
    int find(vector<int> &rankbysize, vector<int> &parent, int node)
    {

        if (node == parent[node])
        {
            return node;
        }
        return parent[node] = find(rankbysize, parent, parent[node]);
    }
    int findCircleNum(vector<vector<int>> &arr)
    {
        unordered_map<int, list<int>> mp;
        int n = arr.size();
        vector<int> rankbysize(n + 1, 1);
        vector<int> parent(n + 1, 0);
        for (int i = 1; i <= n; i++)
        {
            parent[i] = i;
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (arr[i][j] == 1)
                {
                    unionbysize(rankbysize, parent, i + 1, j + 1);
                }
            }
        }
        int res = 0;
        for (int i = 1; i <= n; i++)
        {
            if (parent[i] == i)
            {
                res++;
            }
        }

        return res;
    }
};