#include <bits/stdc++.h>\

vector<int> topologicalSort(vector<vector<int>> &arr, int v, int e)
{
    // Write your code here
    unordered_map<int, list<int>> mp;
    vector<int> ind(v, 0);
    for (int i = 0; i < e; i++)
    {
        int u = arr[i][0];
        int v = arr[i][1];
        mp[u].push_back(v);
        ind[v]++;
    }
    queue<int> que;
    vector<int> res;
    for (int i = 0; i < v; i++)
    {
        if (ind[i] == 0)
        {
            que.push(i);
        }
    }
    while (!que.empty())
    {
        auto temp = que.front();
        que.pop();
        res.push_back(temp);

        for (auto n : mp[temp])
        {
            ind[n]--;
            if (ind[n] == 0)
            {

                que.push(n);
            }
        }
    }

    return res;
}