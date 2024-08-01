#include <bits/stdc++.h>
class Solution
{
public:
    bool dfs(int node, unordered_map<int, list<int>> &mp, vector<int> &vis, vector<int> &path, vector<int> &check)
    {

        path[node] = 1;
        vis[node] = 1;
        for (auto n : mp[node])
        {

            if (!vis[n])
            {
                if (dfs(n, mp, vis, path, check))
                {
                    check[node] = 0;
                    return true;
                    ;
                }
            }
            else if (path[n])
            {
                check[node] = 0;
                return true;
                ;
            }
        }

        check[node] = 1;
        path[node] = 0;
        return false;
    }
    vector<int> eventualSafeNodes(vector<vector<int>> &arr)
    {

        unordered_map<int, list<int>> mp;
        int m = arr.size();
        vector<int> vis(m, 0);
        vector<int> path(m, 0);
        vector<int> check(m, 0);
        for (int i = 0; i < m; i++)
        {

            int n = arr[i].size();
            for (int j = 0; j < n; j++)
            {
                mp[i].push_back(arr[i][j]);
            }
        }

        vector<int> res;
        for (int i = 0; i < m; i++)
        {

            if (!vis[i])
            {
                dfs(i, mp, vis, path, check);
            }
        }

        for (int i = 0; i < m; i++)
        {
            if (check[i] == 1)
            {
                res.push_back(i);
            }
        }
        return res;
    }
};