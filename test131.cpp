#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int decrec(vector<vector<int>> adj, int s, vector<int> &vis, int parent)
{

    vis[s] = true;
    for (auto x : adj[s])
    {
        if (vis[x] == false)
        {
            if (decrec(adj, x, vis, s))
            {
                return true;
            }
        }
        else if (x != parent)
        {
            return true;
        }
    }
    return false;
}

int dec(vector<vector<int>> adj, int n)
{

    vector<int> vis(n + 1, false);
    for (int i = 0; i < n; i++)
    {
        if (vis[i] == false)
        {
            if (decrec(adj, i, vis, -1) == true)
            {
                return true;
            }
        }
    }
    return false;
}

int main()
{
    vector<vector<int>> adj = {{1, 2}, {1, 3}};
    int n = 4;
    cout << "Graph has cycle: " << dec(adj, n) << endl; // Output should be 1 (true)

    return 0;
}