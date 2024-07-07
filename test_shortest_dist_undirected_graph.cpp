#include <bits/stdc++.h>
using namespace std;

// Function to perform topological sort using DFS
void topologicalSortUtil(int v, vector<bool> &visited, stack<int> &Stack, unordered_map<int, list<pair<int, int>>> &adjList)
{
    visited[v] = true;

    for (auto i : adjList[v])
    {
        int node = i.first;
        if (!visited[node])
        {
            topologicalSortUtil(node, visited, Stack, adjList);
        }
    }

    Stack.push(v);
}

// Function to find shortest paths from a given source vertex
vector<int> shortestPathInUAG(int n, vector<vector<int>> &edges, int src)
{
    unordered_map<int, list<pair<int, int>>> adjList;

    // Construct the adjacency list
    for (auto edge : edges)
    {
        int u = edge[0];
        int v = edge[1];
        int w = edge[2];
        adjList[u].push_back({v, w});
        adjList[v].push_back({u, w});
    }

    // Mark all the vertices as not visited
    vector<bool> visited(n, false);
    stack<int> Stack;

    // Perform topological sort
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            topologicalSortUtil(i, visited, Stack, adjList);
        }
    }

    vector<int> dist(n, INT_MAX);
    dist[src] = 0;
    while (Stack.empty() == false)
    {

        auto top = Stack.top();
        Stack.pop();
        if (dist[top] != INT_MAX)
        {

            for (auto nbr : adjList[top])
            {

                if (dist[top] + nbr.second < dist[nbr.first])
                {

                    dist[nbr.first] = dist[top] + nbr.second;
                }
            }
        }
    }
    for (auto i = 0; i < n;i++){
        if(dist[i]==INT_MAX){
            dist[i] = -1;
        }
    }
        return dist;
}

int main()
{
    vector<vector<int>> edges = {
        {0, 1, 4}, {0, 2, 1}, {2, 1, 2}, {1, 3, 1}, {2, 3, 5}};
    int n = 4;
    int src = 0;
    vector<int> distances = shortestPathInUAG(n, edges, src);
    for (int i = 0; i < distances.size(); i++)
    {
        cout << "Distance from node " << src << " to node " << i << " is " << distances[i] << endl;
    }
    return 0;
}
