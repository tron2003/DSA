#include <iostream>
#include <vector>
using namespace std;

bool decrec(vector<vector<int>> &adj, int s, vector<int> &vis, vector<int> &rec)
{
    vis[s] = true;
    rec[s] = true;

    for (auto x : adj[s])
    {
        if (!vis[x] && decrec(adj, x, vis, rec))
        {
            return true;
        }
        else if (rec[x])
        {
            return true;
        }
    }
    rec[s] = false; // Backtrack after exploration
    return false;
}

bool dfs(vector<vector<int>> &adj, int n)
{
    vector<int> vis(n + 1, false);
    vector<int> rec(n + 1, false);
    for (int i = 0; i < n; i++)
    {
        if (!vis[i])
        {
            if (decrec(adj, i, vis, rec))
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
    cout << "Graph has cycle: " << dfs(adj, n) << endl; // Output should be 1 (true)
    return 0;
}
