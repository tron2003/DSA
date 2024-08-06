//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    // Function to find sum of weights of edges of the Minimum Spanning Tree.

    void unionbysize(vector<int> &rankbysize, vector<int> &parent, int u, int v)
    {

        int u_parent = find(rankbysize, parent, u);
        int v_parent = find(rankbysize, parent, v);
        if (u_parent == v_parent)
        {
            return;
        }
        if (rankbysize[u_parent] > rankbysize[v_parent])
        {

            rankbysize[u_parent] += rankbysize[v_parent];
            parent[v_parent] = u_parent;
        }
        else
        {
            rankbysize[v_parent] += rankbysize[u_parent];
            parent[u_parent] = v_parent;
        }
    }
    int find(vector<int> &rankbysize, vector<int> &parent, int node)
    {

        if (node == parent[node])
        {
            return node;
        }
        return parent[node] = find(rankbysize, parent, parent[node]);
    }
    int spanningTree(int v, vector<vector<int>> arr[])
    {
        vector<int> rankbysize(v, 1);
        vector<int> parent(v, 1);
        for (int i = 0; i < v; i++)
        {
            parent[i] = i;
        }
        vector<pair<int, pair<int, int>>> mp;
        for (int i = 0; i < v; i++)
        {

            for (auto x : arr[i])
            {
                int u = i;
                int v = x[0];
                int w = x[1];
                mp.push_back({w, {u, v}});
            }
        }
        sort(mp.begin(), mp.end());
        int ans = 0;
        for (auto x : mp)
        {
            int w = x.first;
            int u = x.second.first;
            int v = x.second.second;

            int u_parent = find(rankbysize, parent, u);
            int v_parent = find(rankbysize, parent, v);
            if (u_parent != v_parent)
            {

                unionbysize(rankbysize, parent, u_parent, v_parent);
                ans += w;
            }
        }
        return ans;
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