class Solution
{
public:
    int dfs(int time, int bob, unordered_map<int, list<int>> &mp,
            vector<bool> &vis, unordered_map<int, int> &path)
    {

        path[bob] = time;
        vis[bob] = true;
        if (bob == 0)
        {
            return true;
        }
        for (auto x : mp[bob])
        {
            if (!vis[x])
            {

                if (dfs(time + 1, x, mp, vis, path))
                {
                    return 1;
                }
            }
        }
        path.erase(bob);
        return false;
    }
    int mostProfitablePath(vector<vector<int>> &arr, int bob, vector<int> &am)
    {
        int n = arr.size();
        unordered_map<int, list<int>> mp;
        for (int i = 0; i < n; i++)
        {

            int x = arr[i][0];
            int y = arr[i][1];
            mp[x].push_back(y);
            mp[y].push_back(x);
        }
        vector<bool> vis(n + 1, false);

        unordered_map<int, int> path;
        int time = 0;
        dfs(time, bob, mp, vis, path);
        int res = INT_MIN;
        for (int i = 0; i < n + 1; i++)
        {
            vis[i] = false;
        }
        queue<pair<int, pair<int, int>>> que;
        que.push({0, {0, 0}});
        while (!que.empty())
        {

            int src = que.front().first;
            int time = que.front().second.first;
            int amount = que.front().second.second;
            que.pop();
            vis[src] = 1;
            if (path.find(src) == path.end())
            {

                amount += am[src];
            }
            else
            {

                if (time < path[src])
                {
                    amount += am[src];
                }
                else if (time == path[src])
                {
                    amount += (am[src] / 2);
                }
            }
            if (mp[src].size() == 1 && src != 0)
            {
                res = max(res, amount);
            }
            for (auto x : mp[src])
            {
                if (!vis[x])
                {
                    que.push({x, {time + 1, amount}});
                }
            }
        }
        return res;
    }
};