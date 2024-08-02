//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

#define pa pair<int, int>
class Solution
{
public:
    // Function to find the shortest distance of all the vertices
    // from the source vertex S.
    vector<int> dijkstra(int v, vector<vector<int>> arr[], int s)
    {
        // Code here
        priority_queue<pa, vector<pa>, greater<pa>> que;
        vector<int> dist(v, 1e9);
        dist[s] = 0;
        que.push({0, s});
        while (!que.empty())
        {

            auto fron = que.top();
            que.pop();
            int u = fron.second;
            int till = fron.first;
            for (auto x : arr[u])
            {
                int v = x[0];
                int vwght = x[1];

                if (till + vwght < dist[v])
                {

                    dist[v] = till + vwght;
                    que.push({dist[v], v});
                }
            }
        }

        return dist;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i = 0;
        while (i++ < E)
        {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1, t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        int S;
        cin >> S;

        Solution obj;
        vector<int> res = obj.dijkstra(V, adj, S);

        for (int i = 0; i < V; i++)
            cout << res[i] << " ";
        cout << endl;
    }

    return 0;
}

// } Driver Code Ends