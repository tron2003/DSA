#include <iostream>
#include <vector>
#include <algorithm>
#include <list>

using namespace std;

class Graph
{
    int V;          // Number of vertices
    list<int> *adj; // Adjacency list

    void APUtil(int u, vector<bool> &visited, vector<int> &disc, vector<int> &low, vector<int> &parent, vector<bool> &ap, int &time);

public:
    Graph(int V);
    void addEdge(int v, int w);
    void findAPs();
};

Graph::Graph(int V)
{
    this->V = V;
    adj = new list<int>[V];
}

void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w);
    adj[w].push_back(v);
}

void Graph::APUtil(int u, vector<bool> &visited, vector<int> &disc, vector<int> &low, vector<int> &parent, vector<bool> &ap, int &time)
{
    int children = 0;
    visited[u] = true;
    disc[u] = low[u] = ++time;

    for (auto v : adj[u])
    {
        if (!visited[v])
        {
            children++;
            parent[v] = u;
            APUtil(v, visited, disc, low, parent, ap, time);

            low[u] = min(low[u], low[v]);

            if (parent[u] == -1 && children > 1)
                ap[u] = true;
            if (parent[u] != -1 && low[v] >= disc[u])
                ap[u] = true;
        }
        else if (v != parent[u])
        {
            low[u] = min(low[u], disc[v]);
        }
    }
}

void Graph::findAPs()
{
    vector<bool> visited(V, false);
    vector<int> disc(V, -1);
    vector<int> low(V, -1);
    vector<int> parent(V, -1);
    vector<bool> ap(V, false);
    int time = 0;

    for (int i = 0; i < V; i++)
        if (!visited[i])
            APUtil(i, visited, disc, low, parent, ap, time);

    for (int i = 0; i < V; i++)
        if (ap[i])
            cout << i << " ";
    cout << endl;
}

int main()
{
    Graph g(6);
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(1, 3);
    g.addEdge(3, 4);
    g.addEdge(4, 5);

    g.findAPs();

    return 0;
}
