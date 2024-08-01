#include <bits/stdc++.h>

inline void dfs(int node, unordered_map<int, list<int>> &mp, vector<int> &vis,
                stack<int> &st)
{

    vis[node] = 1;
    for (auto n : mp[node])
    {

        if (!vis[n])
        {
            dfs(n, mp, vis, st);
        }
    }
    st.push(node);
}

vector<int> topologicalSort(vector<vector<int>> &arr, int v, int e)
{

    stack<int> st;
    unordered_map<int, list<int>> mp;
    vector<int> res;
    vector<int> vis(v, 0);
    for (int i = 0; i < e; i++)
    {
        int u = arr[i][0];
        int v = arr[i][1];
        mp[u].push_back(v);
    }

    for (int i = 0; i < v; i++)
    {
        if (!vis[i])
        {

            dfs(i, mp, vis, st);
        }
    }

    while (!st.empty())
    {

        res.push_back(st.top());
        st.pop();
    }

    return res;
    // Write your code here
}