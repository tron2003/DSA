
#include <bits/stdc++.h>

using namespace std;

void makeset(vector<int> &parent, vector<int> &rank, int n)
{
    for (int i = 0; i <= n; i++)
    {
        rank[i] = 0;
        parent[i] = i;
    }
}

int findparent(vector<int> &parent, vector<int> &rank, int node)
{
    if (parent[node] == node)
    {
        return node;
    }
    return parent[node] = findparent(parent, rank, parent[node]);
}

void makeunion(vector<int> &parent, vector<int> &rank, int i, int j)
{
    int x = findparent(parent, rank, i);
    int y = findparent(parent, rank, j);

    if (rank[x] == rank[y])
    {
        parent[y] = x;
        rank[x]++;
    }
    else if (rank[x] < rank[y])
    {
        parent[x] = y;
    }
    else if (rank[x] > rank[y])
    {
        parent[y] = x;
    }
}

int kruskalMST(int n, vector<vector<int>> &ed)
{
    vector<int> parent(n + 1);
    vector<int> rank(n + 1);
    makeset(parent, rank, n);

    vector<pair<int, pair<int, int>>> arr;
    for (int i = 0; i < ed.size(); i++)
    {
        int u = ed[i][0];
        int v = ed[i][1];
        int w = ed[i][2];
        arr.push_back({w, {u, v}});
    }

    int res = 0;
    sort(arr.begin(), arr.end());
    for (auto x : arr)
    {
        int w = x.first;
        int u = x.second.first;
        int v = x.second.second;
        if (findparent(parent, rank, u) != findparent(parent, rank, v))
        {
            makeunion(parent, rank, u, v);
            res += w;
        }
    }
    return res;
}
