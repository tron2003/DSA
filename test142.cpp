#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

// Function to perform DFS traversal
void dfs(vector<vector<int>> &graph, int v, vector<bool> &visited, stack<int> &order)
{
    visited[v] = true;
    for (int u : graph[v])
    {
        if (!visited[u])
        {
            dfs(graph, u, visited, order);
        }
    }
    order.push(v);
}

// Function to perform DFS traversal on the transposed graph
void dfsTranspose(vector<vector<int>> &graphT, int v, vector<bool> &visited, vector<int> &component)
{
    visited[v] = true;
    component.push_back(v);
    for (int u : graphT[v])
    {
        if (!visited[u])
        {
            dfsTranspose(graphT, u, visited, component);
        }
    }
}

// Function to find strongly connected components using Kosaraju's algorithm
vector<vector<int>> findSCC(vector<vector<int>> &graph, vector<vector<int>> &graphT)
{
    int n = graph.size();
    vector<bool> visited(n, false);
    stack<int> order;

    // Step 1: Perform DFS on the original graph and store finishing times
    for (int i = 0; i < n; ++i)
    {
        if (!visited[i])
        {
            dfs(graph, i, visited, order);
        }
    }

 
    fill(visited.begin(), visited.end(), false);
    vector<vector<int>> SCCs;
    while (!order.empty())
    {
        int v = order.top();
        order.pop();
        if (!visited[v])
        {
            vector<int> component;
            dfsTranspose(graphT, v, visited, component);
            SCCs.push_back(component);
        }
    }

    return SCCs;
}

int main()
{
    // Sample directed graph represented as an adjacency list
    vector<vector<int>> graph = {{1}, {2, 3,5}, {0}, {4}, {3},{1}};
    int n = graph.size();

    // Transpose of the graph
    vector<vector<int>> graphT(n);
    for (int i = 0; i < n; ++i)
    {
        for (int j : graph[i])
        {
            graphT[j].push_back(i);
        }
    }

    // Find strongly connected components
    vector<vector<int>> SCCs = findSCC(graph, graphT);

    // Output SCCs
    cout << "Strongly Connected Components:\n";
    for (const auto &component : SCCs)
    {
        for (int v : component)
        {
            cout << v << " ";
        }
        cout << "\n";
    }

    return 0;
}
