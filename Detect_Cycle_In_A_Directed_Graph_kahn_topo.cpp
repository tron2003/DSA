#include <bits/stdc++.h>
using namespace std;
int helper(unordered_map<int, list<int>> &mp, unordered_map<int, bool> &visit,
           unordered_map<int, bool> &prev, int i)
{

    visit[i] = 1;
    prev[i] = 1;

    for (auto x : mp[i])
    {
        if (!visit[x])
        {
            if (helper(mp, visit, prev, x))
            {

                return true;
            }
        }
        else if (visit[x] == 1 && prev[x] == 1)
        {
            return true;
        }
    }
    prev[i] = 0;
    return false;
}
int detectCycleInDirectedGraph(int n, vector<pair<int, int>> &ed)
{
    // Write your code here.
    vector<vector<int>> mp(n + 1);
    vector<int> indegree(n, 0);
    int res = 0;
    queue<int> que;
    for (auto x : ed)
    {
        mp[x.first - 1].push_back(x.second - 1);
        indegree[x.second - 1]++;
    }
    for (int i = 0; i < n; i++)
    {
        if (indegree[i] == 0)
        {
            que.push(i);
        }
    }
    while (!que.empty())
    {
        int front = que.front();
        que.pop();
        res++;
        for (auto x : mp[front])
        {
            indegree[x]--;
            if (indegree[x] == 0)
            {
                que.push(x);
            }
        }
    }
    // unordered_map<int, bool> prev;
    return res != n;
}