Minimum Spanning Tree //{ Driver Code Starts
#include <bits/stdc++.h>
    using namespace std;

// } Driver Code Ends
class Solution
{
public:
    // Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int v, vector<vector<int>> arr[])
    {
        // code here
        unordered_map<int, list<int>> mp;
        vector<int> dist(v, 0);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> que;
        que.push({0, 0});

        int sum = 0;
        while (!que.empty())
        {
            auto front = que.top();
            int wt = front.first;
            int node = front.second;
            que.pop();
            if (dist[node] == 1)
            {
                continue;
            }
            dist[node] = 1;
            sum += wt;
            for (auto x : arr[node])
            {
                int n = x[0];
                int w = x[1];
                if (dist[n] != 1)
                {
                    que.push({w, n});
                }
            }
        }
        return sum;
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

        Solution obj;
        cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends