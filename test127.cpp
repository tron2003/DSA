#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void bfs(vector<vector<int>> &adj, vector<int> &vis, int s)
{
    queue<int> que;
    vis[s] = true;
    que.push(s);
    while (!que.empty())
    {
        int curr = que.front();
        que.pop();
        cout << curr << " ";
        for (int next : adj[curr])
        {
            if (!vis[next])
            {
                que.push(next);
                vis[next] = true;
            }
        }
    }
}

void bfsb(vector<vector<int>> &adj, int v)
{
    vector<int> vis(v + 1, false);
    for (int i = 1; i <= v; i++)
    {
        if (!vis[i])
        {
            bfs(adj, vis, i);
        }
    }
}

int main()
{
    int v = 78;                      // Number of vertices
    vector<vector<int>> adj(v + 1); // Adjacency list representation of directed graph

    // Add directed edges
    adj[1].push_back(2);
    adj[1].push_back(3);
    adj[2].push_back(4);
    adj[2].push_back(78);
    adj[3].push_back(5);

    cout << "BFS Traversal: ";
    bfsb(adj, v); // Perform BFS traversal starting from any unvisited vertex
    cout << endl;

    return 0;
}
