#include <iostream>
#include <vector>
#include <climits>

using namespace std;

struct Edge
{
    int src, dest, weight;
};

void bellmanFord(vector<Edge> &edges, int V, int src)
{
    vector<int> dist(V, INT_MAX);
    dist[src] = 0;

    // Relax all edges |V| - 1 times
    for (int i = 0; i < V - 1; ++i)
    {
        for (const auto &edge : edges)
        {
            int u = edge.src;
            int v = edge.dest;
            int weight = edge.weight;
            if (dist[u] != INT_MAX && dist[u] + weight < dist[v])
            {
                dist[v] = dist[u] + weight;
            }
        }
    }


    

    // Print the shortest distances
    cout << "Vertex\tDistance from Source\n";
    for (int i = 0; i < V; ++i)
    {
        cout << i << "\t" << dist[i] << "\n";
    }
}

int main()
{
    int V = 5; // Number of vertices
    int E = 8; // Number of edges
    vector<Edge> edges = {
        {0, 1, -1}, {0, 2, 4}, {1, 2, 3}, {1, 3, 2}, {1, 4, 2}, {3, 2, 5}, {3, 1, 1}, {4, 3, -3}};
    int src = 0; // Source vertex

    bellmanFord(edges, V, src);

    return 0;
}
