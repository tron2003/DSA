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

    int largestIsland(vector<vector<int>> &arr)
    {

        int m = arr.size();
        vector<int> rankbysize(m * m, 1);
        vector<int> parent(m * m, 0);
        for (int i = 0; i < m * m; i++)
        {
            parent[i] = i;
        }
        vector<int> drow = {0, 0, -1, 1};
        vector<int> dcol = {1, -1, 0, 0};

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < m; j++)
            {

                if (arr[i][j] == 0)
                {
                    continue;
                }
                else
                {

                    for (int k = 0; k < 4; k++)
                    {
                        int newx = drow[k] + i;
                        int newy = dcol[k] + j;
                        if (newx >= 0 && newx <= m - 1 && newy >= 0 &&
                            newy <= m - 1 && arr[newx][newy] == 1)
                        {

                            int node = i * m + j;
                            int newnode = newx * m + newy;
                            unionbysize(rankbysize, parent, node, newnode);
                        }
                    }
                }
            }
        }
        int res = 0;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (arr[i][j] == 1)
                {
                    continue;
                }
                else
                {
                    set<int> set;
                    for (int k = 0; k < 4; k++)
                    {
                        int newx = drow[k] + i;
                        int newy = dcol[k] + j;
                        if (newx >= 0 && newx <= m - 1 && newy >= 0 &&
                            newy <= m - 1 && arr[newx][newy] == 1)
                        {

                            int node = i * m + j;
                            int newnode = newx * m + newy;
                            set.insert(find(parent, newnode));
                        }
                    }
                    int size = 0;
                    for (auto it : set)
                    {
                        size += rankbysize[it];
                    }
                    res = max(res, size + 1);
                }
            }
        }
        for (int i = 0; i < m * m; i++)
        {
            res = max(rankbysize[i], res);
        }
        return res;
    }
};