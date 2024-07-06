#include <bits/stdc++.h>
using namespace std;
vector<pair<pair<int, int>, int>>
calculatePrimsMST(int n, int m, vector<pair<pair<int, int>, int>> &g)
{
    // Write your code here.
    unordered_map<int, list<pair<int, int>>> arr;
    for (int i = 0; i < g.size(); i++)
    {
        int u = g[i].first.first;
        int v = g[i].first.second;
        int w = g[i].second;
        arr[u].push_back(make_pair(v, w));
        arr[v].push_back(make_pair(u, w));
    }
    vector<bool> mst(n + 1, 0);
    vector<int> key(n + 1, INT_MAX);
    vector<int> parent(n + 1, -1);
    key[1] = 0;
    mst[1] = 0;
    for (int i = 1; i <= n; i++)
    {
        int mini = INT_MAX;
        int u;
        for (int v = 1; v <= n; v++)
        {
            if (mst[v] == 0 && key[v] < mini)
            {

                mini = key[v];
                u = v;
            }
        }
        mst[u] = 1;

        for (auto node : arr[u])
        {

            int v = node.first;
            int w = node.second;
            if (mst[v] == 0 && w < key[v])
            {
                key[v] = w;
                parent[v] = u;
            }
        }
    }

    vector<pair<pair<int, int>, int>> res;
    for (int i = 2; i <= n; i++)
    {

        res.push_back({{parent[i], i}, key[i]});
    }
    return res;
}
