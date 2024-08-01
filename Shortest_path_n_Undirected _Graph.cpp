//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution
{
public:
    vector<int> shortestPath(vector<vector<int>> &arr, int n, int m, int src)
    {
        // code here
        unordered_map<int, list<int>> mp;
        for (int i = 0; i < m; i++)
        {
            int u = arr[i][0];
            int v = arr[i][1];
            mp[u].push_back(v);
            mp[v].push_back(u);
        }
        queue<int> que;
        vector<int> dist(n, 1e9);
        que.push(src);
        dist[src] = 0;
        // vector<int<
        while (!que.empty())
        {

            int temp = que.front();
            que.pop();
            for (auto node : mp[temp])
            {

                if (dist[temp] + 1 < dist[node])
                {
                    dist[node] = dist[temp] + 1;
                    que.push(node);
                }
            }
        }
        for (int i = 0; i < n; i++)
        {
            if (dist[i] == 1e9)
            {
                dist[i] = -1;
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
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;

        for (int i = 0; i < m; ++i)
        {
            vector<int> temp;
            for (int j = 0; j < 2; ++j)
            {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }

        int src;
        cin >> src;

        Solution obj;

        vector<int> res = obj.shortestPath(edges, n, m, src);

        for (auto x : res)
        {
            cout << x << " ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends