#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void fuck(vector<vector<int>> &adj, int v, int s)
{
    vector<bool> vis(v , false);
    vector<int> dist(v, INT_MAX);
    queue<int> que;
    que.push(s);
    vis[s] = true;
    dist[s] = 0;
    while (!que.empty())
    {
        auto curr = que.front();
        que.pop();
        for (auto x : adj[curr])
        {
            if (vis[x] == false)
            {
                dist[x] = dist[curr] + 1;
                vis[x] = true;
                que.push(x);
            }
        }
    }
    for(auto x:dist){
        cout << x << " ";
    }
}

int main()
{
    int v = 4;                     // Number of vertices
    vector<vector<int>> adj(v +1); // Adjacency list representation of directed graph

    // Add directed edges
    adj[0].push_back(1);
    adj[0].push_back(2);
    adj[1].push_back(2);
    adj[1].push_back(3);
    adj[2].push_back(3);

    cout << "DFS Traversal: ";
    fuck(adj, v,0); // Perform DFS traversal starting from vertex 1
    // for(int )
    cout << endl;
    return 0;
}