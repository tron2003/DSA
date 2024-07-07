#include <bits/stdc++.h>
using namespace std;

void helper(unordered_map<int, list<int>> &arr, int &time, int parent, int node,
            vector<int> &disc, vector<int> &low, vector<bool> &visit, vector<bool> &ap, int &children)
{
    visit[node] = true;
    disc[node] = low[node] = time++;
    children = 0;

    for (auto nbr : arr[node])
    {
        if (nbr == parent)
        {
            continue;
        }
        if (!visit[nbr])
        {
            children++;
            helper(arr, time, node, nbr, disc, low, visit, ap, children);
            low[node] = min(low[node], low[nbr]);

            if (parent == -1 && children > 1)
            {
                ap[node] = true;
            }
            if (parent != -1 && low[nbr] >= disc[node])
            {
                ap[node] = true;
            }
        }
        else
        {
            low[node] = min(low[node], disc[nbr]);
        }
    }
}

vector<int> findArticulationPoints(vector<vector<int>> &ed, int v, int e)
{
    unordered_map<int, list<int>> arr;
    for (int i = 0; i < ed.size(); i++)
    {
        int u = ed[i][0];
        int v = ed[i][1];
        arr[u].push_back(v);
        arr[v].push_back(u);
    }
    vector<int> disc(v, -1);
    vector<int> low(v, -1);
    vector<bool> visit(v, false);
    vector<bool> ap(v, false);
    int time = 0;
    int children = 0;

    for (int i = 0; i < v; i++)
    {
        if (!visit[i])
        {
            helper(arr, time, -1, i, disc, low, visit, ap, children);
        }
    }

    vector<int> result;
    for (int i = 0; i < v; i++)
    {
        if (ap[i])
        {
            result.push_back(i);
        }
    }
    return result;
}

int main()
{
    // Graph:
    // 0 - 1
    // |   |
    // 2 - 3

    vector<vector<int>> edges = {{0, 1}, {0, 2}, {1, 3}, {2, 3}};
    int v = 4; // Number of vertices
    int e = 4; // Number of edges

    vector<int> articulationPoints = findArticulationPoints(edges, v, e);

    if (articulationPoints.empty())
    {
        cout << "No articulation points found." << endl;
    }
    else
    {
        for (auto point : articulationPoints)
        {
            cout << "Articulation Point: " << point << endl;
        }
    }

    return 0;
}

// Expected output:
// No articulation points found.
