#include <iostream>
#include <bits/stdc++.h>
using namespace std;
vector<int> sort(vector<vector<int>> adj, int n)
{
    vector<int> in(n + 1, 0);
    vector<int> res;
    queue<int> que;
    for (auto i = 1; i <= n; i++)
    {
        for (auto x : adj[i])
        {
            in[x]++;
        }
    }
    for (auto i = 1; i <= n; i++)
    {
        if (in[i] == 0)
        {
            que.push(i);
        }
    }

    while (!que.empty())
    {

        auto curr = que.front();
        que.pop();
        res.push_back(curr);
        for (auto x : adj[curr])
        {
            in[x]--;
            if (in[x] == 0)
            {
                que.push(x);
            }
        }
    }

    return res;
}

int main()
{
    vector<vector<int>> adj = {{}, {2, 3}, {4}, {4, 5}, {}, {}};
    int n = 5;

    vector<int> ordering = sort(adj, n);

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