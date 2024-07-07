#include <bits/stdc++.h>
using namespace std;

void helper(unordered_map<int, list<int>> &arr, int time, int parent, int node,
            vector<int> &disc, vector<int> &ear, vector<bool> &visit, vector<vector<int>> &res)
{
    visit[node] = 1;
    ear[node] = disc[node] = time++;

    for (auto nbr : arr[node])
    {
        if (nbr == parent)
        {

            continue;
        }
        if (!visit[nbr])
        {

            helper(arr, time, node, nbr, disc, ear, visit, res);
            ear[node] = min(ear[nbr], ear[node]);
            if (ear[nbr] > disc[node])
            {
                vector<int> temp;
                temp.push_back(node);
                temp.push_back(nbr);
                res.push_back(temp);
            }
        }
        else
        {
            ear[node] = min(ear[node], disc[nbr]);
        }
    }
}

vector<vector<int>> findBridges(vector<vector<int>> &ed, int v, int e)
{
    unordered_map<int, list<int>> arr;
    for (int i = 0; i < ed.size(); i++)
    {
        int u = ed[i][0];
        int v = ed[i][1];
        arr[u].push_back(v);
        arr[v].push_back(u);
    }
    vector<int> disc(v + 1, -1);
    vector<int> ear(v + 1, -1);
    int parent = -1;
    int time = 0;
    vector<bool> visit(v + 1, 0);
    vector<vector<int>> res;
    for (int i = 0; i < v; i++)
    {
        if (!visit[i])
        {
            helper(arr, time, parent, i, disc, ear, visit, res);
        }
    }
    return res;
}