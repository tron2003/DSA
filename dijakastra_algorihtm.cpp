#include <bits/stdc++.h>
using namespace std;

vector<int> dijkstra(vector<vector<int>> &vec, int n, int edges, int src)
{
    vector<int> dist(n, INT_MAX);
    unordered_map<int, list<pair<int, int>>> adjList;

    // Construct the adjacency list
    for (int i = 0; i < edges; i++)
    {
        int u = vec[i][0];
        int v = vec[i][1];
        int w = vec[i][2];
        adjList[u].push_back({v, w});
        adjList[v].push_back({u, w});
    }

    dist[src] = 0;
    set<pair<int, int>> st;
    st.insert({0, src});

    while (!st.empty())
    {
        auto top1 = *(st.begin());
        int nodedistance = top1.first;
        int node = top1.second;
        st.erase(st.begin());

        for (auto nbr : adjList[node])
        {
            int neighbor = nbr.first;
            int weight = nbr.second;
            if (nodedistance + weight < dist[neighbor])
            {
                auto it = st.find({dist[neighbor], neighbor});
                if (it != st.end())
                {
                    st.erase(it);
                }
                dist[neighbor] = nodedistance + weight;
                st.insert({dist[neighbor], neighbor});
            }
        }
    }

    return dist;
}

int main(){

    return 0;
}