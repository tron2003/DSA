//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    int timer = 1;
    void dfs(int node, int parent, vector<int> arr[], vector<int> &vis, vector<int> &low, vector<int> &first, vector<int> &mark)

    {
        vis[node] = 1;
        low[node] = first[node] = timer;
        timer++;
        int child = 0;
        for (auto n : arr[node])
        {

            if (n == parent)
            {
                continue;
            }
            if (!vis[n])
            {
                dfs(n, node, arr, vis, low, first, mark);
                low[node] = min(low[n], low[node]);
                if (parent != -1 && low[n] >= first[node])
                {
                    mark[node] = 1;
                }
                child++;
            }
            else
            {
                low[node] = min(low[node], first[n]);
            }
        }
        if (child > 1 && parent == -1)
        {
            mark[node] = 1;
        }
    }
    vector<int> articulationPoints(int v, vector<int> arr[])
    {
        // Code here
        int n = sizeof(arr) / sizeof(arr[0]);
        vector<int> vis(v, 0);
        vector<int> low(v, 0);
        vector<int> first(v, 0);
        vector<int> mark(v, 0);
        for (int i = 0; i < v; i++)
        {
            if (!vis[i])
            {
                dfs(i, -1, arr, vis, low, first, mark);
            }
        }
        vector<int> res;
        for (int i = 0; i < v; i++)
        {
            if (mark[i] == 1)
            {
                res.push_back(i);
            }
        }
        if (res.size() == 0)
        {
            return {-1};
        }
        return res;
    }
};

//{ Driver Code Starts.

int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++)
        {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        vector<int> ans = obj.articulationPoints(V, adj);
        for (auto i : ans)
            cout << i << " ";
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends