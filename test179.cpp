#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Structure to represent an edge in the graph
struct Edge
{
    int src, dest, weight;
};

// Structure to represent the Union-Find data structure
struct UnionFind
{
    vector<int> parent, rank;

    UnionFind(int n)
    {
        parent.resize(n);
        rank.resize(n);
        for (int i = 0; i < n; ++i)
        {
            parent[i] = i;
            rank[i] = 0;
        }
    }

    // Find the parent of a node (with path compression)
    int find(int u)
    {
        if (parent[u] != u)
        {
            parent[u] = find(parent[u]);
        }
        return parent[u];
    }

    // Union operation to merge two sets (with union by rank)
    void merge(int u, int v)
    {
        int rootU = find(u);
        int rootV = find(v);
        if (rootU != rootV)
        {
            if (rank[rootU] < rank[rootV])
            {
                parent[rootU] = rootV;
            }
            else if (rank[rootU] > rank[rootV])
            {
                parent[rootV] = rootU;
            }
            else
            {
                parent[rootV] = rootU;
                rank[rootU]++;
            }
        }
    }
};

// Function to compare edges by weight for sorting
bool compareEdges(const Edge &a, const Edge &b)
{
    return a.weight < b.weight;
}

// Function to find the MST of a graph using Kruskal's algorithm with Union-Find
vector<Edge> kruskalMST(const vector<Edge> &edges, int V)
{
    // Sort the edges by weight
    vector<Edge> sortedEdges = edges;
    sort(sortedEdges.begin(), sortedEdges.end(), compareEdges);

    // Initialize an empty MST
    vector<Edge> MST;

    // Initialize the Union-Find data structure
    UnionFind uf(V);

    // Iterate through the sorted edges
    for (const Edge &edge : sortedEdges)
    {
        // If adding this edge does not create a cycle, add it to the MST
        if (uf.find(edge.src) != uf.find(edge.dest))
        {
            MST.push_back(edge);
            uf.merge(edge.src, edge.dest);
        }
    }

    return MST;
}

int main()
{
    int V = 4; // Number of vertices
    int E = 5; // Number of edges
    vector<Edge> edges = {
        {0, 1, 10},
        {0, 2, 6},
        {0, 3, -5}, // Negative edge weight
        {1, 3, 15},
        {2, 3, 4}};

    // Find the MST of the graph using Kruskal's algorithm with Union-Find
    vector<Edge> MST = kruskalMST(edges, V);

    // Print the edges of the MST
    cout << "Edges of the minimum spanning tree:" << endl;
    for (const Edge &edge : MST)
    {
        cout << edge.src << " - " << edge.dest << " : " << edge.weight << endl;
    }

    return 0;
}
