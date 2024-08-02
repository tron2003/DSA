vector<int> shortestPath(int n, int m, vector<vector<int>> &arr)
{
    // Code here
    vector<int> parent(n + 1, 0);
    unordered_map<int, list<pa>> mp;
    for (int i = 0; i < m; i++)
    {

        int u = arr[i][0];
        int v = arr[i][1];
        int w = arr[i][2];
        mp[u].push_back({v, w});
        mp[v].push_back({u, w});
    }
    for (int i = 0; i <= n; i++)
    {
        parent[i] = i;
    }
    parent[1] = 1;

    vector<int> dist(n + 1, 1e9);
    priority_queue<pa, vector<pa>, greater<pa>> que;
    que.push({0, 1});
    dist[1] = 0;
    while (!que.empty())
    {

        auto front = que.top();
        int wgt = front.first;
        int node = front.second;
        que.pop();
        for (auto x : mp[node])
        {

            int v = x.first;
            int w = x.second;
            if (w + wgt < dist[v])
            {
                dist[v] = wgt + w;
                que.push({dist[v], v});
                parent[v] = node;
            }
        }
    }
    if (dist[n] == 1e9)
    {
        return {-1};
    }
    int node = n;
    vector<int> res;
    while (parent[node] != node)
    {
        res.push_back(node);
        node = parent[node];
    }
    res.push_back(1);
    res.push_back(dist[n]);
    reverse(res.begin(), res.end());
    return res;
}