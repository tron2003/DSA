int finde(vector<int> &rankbysize, vector<int> &parent, int node)
{

    if (node == parent[node])
    {
        return node;
    }
    return parent[node] = finde(rankbysize, parent, parent[node]);
}
void unionbysize(vector<int> &rankbysize, vector<int> &parent, int u, int v)
{

    int u_parent = finde(rankbysize, parent, u);
    int v_parent = finde(rankbysize, parent, v);
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

vector<int> numOfIslandsII(int n, int m, vector<vector<int>> &arr)
{
    vector<int> rankbysize(n * m, 1);
    vector<int> parent(n * m);
    for (int i = 0; i < n * m; ++i)
    {
        parent[i] = i;
    }
    vector<vector<int>> vis(n, vector<int>(m, 0));
    int cnt = 0;
    vector<int> res;
    for (auto x : arr)
    {

        int row = x[0];
        int col = x[1];
        if (vis[row][col] == 1)
        {
            res.push_back(cnt);
            continue;
        }
        vis[row][col] = 1;
        cnt++;
        vector<int> drow = {0, 0, 1, -1};
        vector<int> dcol = {1, -1, 0, 0};
        for (int i = 0; i < 4; i++)
        {
            int newx = row + drow[i];
            int newy = col + dcol[i];
            if (newx <= n - 1 && newx >= 0 && newy <= m - 1 && newy >= 0)
            {

                if (vis[newx][newy] == 1)
                {

                    int node = row * m + col;
                    int adjnode = newx * m + newy;
                    if (finde(rankbysize, parent, node) !=
                        finde(rankbysize, parent, adjnode))
                    {

                        cnt--;
                        unionbysize(rankbysize, parent, node, adjnode);
                    }
                }
            }
        }
        res.push_back(cnt);
    }
    return res;
}