#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Edge
{
public:
    int src, dest, weight;
    Edge(int s, int d, int w) : src(s), dest(d), weight(w) {}
};

class Graph
{
    int V;              // Number of vertices
    vector<Edge> edges; // List of all edges

public:
    Graph(int V);
    void addEdge(int src, int dest, int weight);
    void kruskalMST();

private:
    int find(vector<int> &parent, int i);
    void unionSets(vector<int> &parent, vector<int> &rank, int x, int y);
    void printMST(const vector<Edge> &result);
};

Graph::Graph(int V)
{
    this->V = V;
}

void Graph::addEdge(int src, int dest, int weight)
{
    edges.push_back(Edge(src, dest, weight));
}

int Graph::find(vector<int> &parent, int i)
{
    if (parent[i] != i)
    {
        parent[i] = find(parent, parent[i]);
    }
    return parent[i];
}

void Graph::unionSets(vector<int> &parent, vector<int> &rank, int x, int y)
{
    int xroot = find(parent, x);
    int yroot = find(parent, y);

    if (rank[xroot] < rank[yroot])
    {
        parent[xroot] = yroot;
    }
    else if (rank[xroot] > rank[yroot])
    {
        parent[yroot] = xroot;
    }
    else
    {
        parent[yroot] = xroot;
        rank[xroot]++;
    }
}

void Graph::printMST(const vector<Edge> &result)
{
    cout << "Following are the edges in the constructed MST\n";
    for (const auto &edge : result)
    {
        cout << edge.src << " -- " << edge.dest << " == " << edge.weight << endl;
    }
}

void Graph::kruskalMST()
{
    vector<Edge> result; // Store the resultant MST
    int e = 0;           // Number of edges in MST
    int i = 0;           // Index variable for sorted edges

    // Step 1: Sort all the edges in non-decreasing order of their weight
    sort(edges.begin(), edges.end(), [](Edge a, Edge b)
         { return a.weight < b.weight; });

    // Allocate memory for creating V subsets
    vector<int> parent(V);
    vector<int> rank(V, 0);

    // Create V subsets with single elements
    for (int v = 0; v < V; v++)
    {
        parent[v] = v;
    }

    // Number of edges to be taken is equal to V-1
    while (e < V - 1 && i < edges.size())
    {
        // Step 2: Pick the smallest edge. Check if it forms a cycle with the spanning tree
        Edge next_edge = edges[i++];

        int x = find(parent, next_edge.src);
        int y = find(parent, next_edge.dest);

        // If including this edge doesn't cause a cycle, include it in the result
        // and increment the index of the result for the next edge
        if (x != y)
        {
            result.push_back(next_edge);
            unionSets(parent, rank, x, y);
            e++;
        }
    }

    // Print the contents of the MST
    printMST(result);
}

int main()
{
    int V = 4; // Number of vertices in graph
    Graph g(V);

    g.addEdge(0, 1, 10);
    g.addEdge(0, 2, 6);
    g.addEdge(0, 3, 5);
    g.addEdge(1, 3, 15);
    g.addEdge(2, 3, 4);

    g.kruskalMST();

    return 0;
}
