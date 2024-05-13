#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// st.

void dfs(vector<vector<int>> arr, int i, vector<int> &vis, stack<int> &st)
{
    vis[i] = true;
    int n = arr.size();
    for (auto x : arr[i])
    {
        if (!vis[x])
        {
            dfs(arr, x, vis, st);
        }
    }
    st.push(i);
}
void dfst(vector<vector<int>> arr, int i, vector<int> &vis, vector<int> &st)
{
    vis[i] = true;
    int n = arr.size();
    for (auto x : arr[i])
    {
        if (!vis[x])
        {
            dfst(arr, x, vis, st);
        }
    }
    st.push_back(i);
}
vector<vector<int>> func(vector<vector<int>> arr)
{
    int n = arr.size();
    vector<vector<int>> res;
    vector<int> vis(n, false);
    stack<int> st;

    // Step 1: Perform DFS and fill the stack with vertices in order of their finishing time
    for (int i = 0; i < n; i++)
    {
        if (!vis[i])
        {
            dfs(arr, i, vis, st);
        }
    }

    // Step 2: Transpose the graph
    vector<vector<int>> rev(n); // Transposed graph
    for (int i = 0; i < n; i++)
    {
        for (auto x : arr[i])
        {
            rev[x].push_back(i);
        }
    }

    // Step 3: Perform DFS on the transposed graph in the order of vertices in the stack
    fill(vis.begin(), vis.end(), false);
    while (!st.empty())
    {
        int v = st.top();
        st.pop();
        if (!vis[v])
        {
            vector<int> component;
            dfst(rev, v, vis, component);
            res.push_back(component);
        }
    }

    return res;
}

int main()
{
    vector<vector<int>> graph1 = {
        {1},    // 0 -> 1
        {2},    // 1 -> 2
        {0, 3}, // 2 -> 0, 3
        {4},    // 3 -> 4
        {}      // 4
    };

    vector<vector<int>> result1 = func(graph1);
    cout << "Test Case 1: ";
    for (const auto &component : result1)
    {
        for (int v : component)
        {
            cout << v << " ";
        }
        cout << "\n";
    }

    vector<vector<int>> graph2 = {
        {1, 2}, // 0 -> 1, 2
        {2},    // 1 -> 2
        {0, 3}, // 2 -> 0, 3
        {4},    // 3 -> 4
        {3}     // 4 -> 3
    };

    vector<vector<int>> result2 = func(graph2);
    cout << "\nTest Case 2: ";
    for (const auto &component : result2)
    {
        for (int v : component)
        {
            cout << v << " ";
        }
        cout << "\n";
    }

    return 0;
}