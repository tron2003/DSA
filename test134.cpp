#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int sort(vector<vector<int>> adj, int n)
{
    int res = 0;
    queue<int> que;
    vector<int> in(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        for (auto x : adj[i])
        {
            in[x]++;
        }
    }
    for (int i = 0; i <= n; i++)
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
        for (auto x : adj[curr])
        {
            in[x]--;
            if (in[x] == 0)
            {
                que.push(x);
            }
        }
        res++;
    }

    return res != n;
}

int main()
{
    vector<vector<int>> graph = {
        {1}, // Node 0 points to node 1
        {2}, // Node 1 points to node 2
        {3}, // Node 2 points to node 3
        {1}  // Node 3 points back to node 1, forming a cycle
    };

    if (sort(graph,5))
    {
        cout << "Cycle detected!" << endl;
    }
    else
    {
        cout << "No cycle detected." << endl;
    }

    return 0;

    return 0;
}