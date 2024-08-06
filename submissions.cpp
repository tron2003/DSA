class Solution
{
public:
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
    int makeConnected(int n, vector<vector<int>> &arr)
    {
        vector<int> rankbysize(n, 1);
        vector<int> parent(n, 0);
        for (int i = 0; i < n; i++)
        {
            parent[i] = i;
        }

        int extra = 0;

        for (int i = 0; i < arr.size(); i++)
        {
            int u = arr[i][0];
            int v = arr[i][1];
            if (find(rankbysize, parent, u) == find(rankbysize, parent, v))
            {
                extra++;
            }
            else
            {
                unionbysize(rankbysize, parent, u, v);
            }
        }
        int cnt = 0;
        for (int i = 0; i < n; i++)
        {
            if (parent[i] == i)
            {
                cnt++;
            }
        }
        if (extra >= cnt - 1)
        {
            return cnt - 1;
        }
        else
        {
            return -1;
        }
    }
};