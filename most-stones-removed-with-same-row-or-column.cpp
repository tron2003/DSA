class Solution
{
public:
    int find(vector<int> &parent, int node)
    {

        if (node == parent[node])
        {
            return node;
        }
        return parent[node] = find(parent, parent[node]);
    }
    void unionbysize(vector<int> &rankbysize, vector<int> &parent, int u,
                     int v)
    {

        int u_parent = find(parent, u);
        int v_parent = find(parent, v);
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

    int removeStones(vector<vector<int>> &arr)
    {
        int m = arr.size();
        int n = arr[0].size();
        int maxrow = 0;
        int maxcol = 0;
        for (auto it : arr)
        {
            maxrow = max(it[0], maxrow);
            maxcol = max(it[1], maxcol);
        }

        vector<int> rankbysize(maxrow + maxcol + 2, 1);
        vector<int> parent(maxrow + maxcol + 2);
        for (int i = 0; i < maxrow + maxcol + 2; i++)
        {
            parent[i] = i;
        }
        unordered_map<int, int> mp;
        for (auto it : arr)
        {

            int noderow = it[0];
            int nodecol = it[1] + maxrow + 1;
            unionbysize(rankbysize, parent, noderow, nodecol);
            mp[noderow] = 1;
            mp[nodecol] = 1;
        }
        int cnt = 0;
        for (auto x : mp)
        {
            if (find(parent, x.first) == x.first)
            {
                cnt++;
            }
        }
        return m - cnt;
    }
};