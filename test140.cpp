#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

// Function to find sum of weights of edges of the Minimum Spanning Tree.
int spanningTree(int V, int E, int edges[][3])
{
    // Create an adjacency list representation of the graph
    vector<vector<int>> adj[V];

    // Fill the adjacency list with edges and their weights
    for (int i = 0; i < E; i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];
        int wt = edges[i][2];
        adj[u].push_back({v, wt});
        adj[v].push_back({u, wt});
    }

    // Create a priority queue to store edges with their weights
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    int res = 0;
    pq.push({0, 0});
    vector<int> vis(V, false);

    while(!pq.empty()){
        auto curr = pq.top();
        pq.pop();

        int wt = curr.first;
        int v = curr.second;
        if(vis[v]==true){
            continue;
        }
        vis[v] = true;
        res += wt;
        for(auto x:adj[v]){
            if(vis[x[0]]==false){
                pq.push({x[1], x[0]});
            }
        }
    }

    // Create a visited array to keep track of visited vertices
    
    

    return res; // Return the sum of edge weights of the Minimum Spanning Tree
}

int main()
{
    int graph[][3] = {{0, 1, 5},
                      {1, 2, 3},
                      {0, 2, 1}};

    // Function call
    cout << spanningTree(3, 3, graph) << endl;

    return 0;
}
