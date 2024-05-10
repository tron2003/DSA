#include <iostream>
#include <vector>
#include <stack>
#include <limits>

using namespace std;

// Function to perform Depth-First Search (DFS)
void dfs(int x, stack<int> &st, vector<vector<int>> &adj, vector<int> &vis)
{
    vis[x] = true;
    for (auto i : adj[x])
    {
        if (vis[i] == false)
        {
            dfs(i, st, adj, vis);
        }
    }
    st.push(x);
}

// Function to perform topological sorting using DFS
vector<int> topologicalSort(vector<vector<int>> &adj, int n)
{
    vector<int> res;
    vector<int> vis(n + 1, false);
    stack<int> st;
    for (int i = 1; i <= n; i++)
    {
        if (vis[i] == false)
        {
            dfs(i, st, adj, vis);
        }
    }
    while (!st.empty())
    {
        res.push_back(st.top());
        st.pop();
    }
    return res;
}

// Function to calculate the shortest path distances using topological sorting
vector<int> shortestPath(vector<vector<int>> &adj, vector<vector<int>> &weights, int n)
{
    vector<int> topsort = topologicalSort(adj, n);
    vector<int> dist(n + 1, numeric_limits<int>::max());
    dist[topsort[0]] = 0; // Starting node has distance 0
    for (auto x : topsort)
    {
        for (int i = 0; i < adj[x].size(); i++)
        {
            int y = adj[x][i];
            int w = weights[x][i];
            if (dist[y] > dist[x] + w)
            {
                dist[y] = dist[x] + w;
            }
        }
    }
    return dist;
}

int main()
{
    vector<vector<int>> adj = {{}, {2, 3}, {4}, {4, 5}, {}, {}};
    vector<vector<int>> weights = {{},
     {1, 1}, {2}, {1, 1}, {}, {}};
    int n = 5;

    vector<int> ordering = topologicalSort(adj, n);

    if (ordering.size() == n)
    {
        cout << "Topological Ordering:";
        for (int vertex : ordering)
        {
            cout << " " << vertex;
        }
        cout << endl;

        vector<int> dist = shortestPath(adj, weights, n);
        cout << "Shortest Path Distances:";
        for (int i = 1; i <= n; i++)
        {
            cout << " " << dist[i];
        }
        cout << endl;
    }
    else
    {
        cout << "The graph has a cycle." << endl;
    }

    return 0;
}
