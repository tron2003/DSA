//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    // Function to find number of strongly connected components in the graph.
    void helper(vector<vector<int>> &arr, vector<int> &vis, int node, stack<int> &st)
    {

        vis[node] = 1;
        for (auto n : arr[node])
        {
            if (vis[n] == 0)
            {
                helper(arr, vis, n, st);
            }
        }
        st.push(node);
    }
    void helper2(unordered_map<int, list<int>> &arr, vector<int> &vis, int node)
    {

        vis[node] = 1;
        for (auto n : arr[node])
        {
            if (vis[n] == 0)
            {
                helper2(arr, vis, n);
            }
        }
    }
    int kosaraju(int v, vector<vector<int>> &arr)
    {
        // code herevec
        int n = arr.size();
        vector<int> vis(n, 0);
        stack<int> st;
        for (int i = 0; i < v; i++)
        {

            if (vis[i] == 0)
            {
                helper(arr, vis, i, st);
            }
        }
        unordered_map<int, list<int>> mp;
        for (int i = 0; i < v; i++)
        {
            vis[i] = 0;
            for (auto x : arr[i])
            {

                mp[x].push_back(i);
            }
        }
        int res = 0;

        while (!st.empty())
        {

            auto x = st.top();
            st.pop();
            if (vis[x] == 1)
            {
                continue;
            }
            res++;
            helper2(mp, vis, x);
        }

        return res;
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

        vector<vector<int>> adj(V);

        for (int i = 0; i < E; i++)
        {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.kosaraju(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends