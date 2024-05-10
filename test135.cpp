#include <iostream>
#include <vector>
#include <stack>

using namespace std;

void dfs(int x, stack<int> &st, vector<vector<int>> &adj, vector<int> &vis)
{
    vis[x] = true;
    for (auto i : adj[x])
    {
        if (vis[i] == false)
        {
            dfs(i, st, adj, vis);
        }
    }
    st.push(x);
}

vector<int> topologicalSort(vector<vector<int>> &adj, int n)
{
    vector<int> res;
    vector<int> vis(n + 1, false);
    stack<int> st;
    for (int i = 1; i <= n; i++)
    {
        if (vis[i] == false)
        {
            dfs(i, st, adj, vis);
        }
    }
    while (!st.empty())
    {
        res.push_back(st.top());
        st.pop();
    }
    return res;
}

int main()
{
    vector<vector<int>> adj = {{}, {2, 3}, {4}, {4, 5}, {}, {}};
    int n = 5;

    vector<int> ordering = topologicalSort(adj, n);

    if (ordering.size() == n)
    {
        cout << "Topological Ordering:";
        for (int vertex : ordering)
        {
            cout << " " << vertex;
        }
        cout << endl;
    }
    else
    {
        cout << "The graph has a cycle." << endl;
    }

    return 0;
}
