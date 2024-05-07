#include <iostream>
#include <bits/stdc++.h>
using namespace std;
void dfsrec(vector<vector<int>> adj, vector<int> &vis, int s)
{
    vis[s] = true;
    cout << s << " ";
    for (auto x : adj[s])
    {
        if (vis[x] == false)
        {
            dfsrec(adj, vis, x);
        }
    }
}

void dfs(vector<vector<int>> adj, int s, int v)
{
    vector<int> vis(v + 1, false);
    dfsrec(adj, vis, s);
}
int main()
{
    int v = 90;                      // Number of vertices
    vector<vector<int>> adj(v + 1); // Adjacency list representation of directed graph

    // Add directed edges
    adj[1].push_back(2);
    adj[1].push_back(90);
    adj[2].push_back(3);
    adj[3].push_back(4);
    adj[4].push_back(5);
    adj[5].push_back(1);

    cout << "DFS Traversal: ";
    dfs(adj, 1, v); // Perform DFS traversal starting from vertex 1
    cout << endl;

    return 0;
}
