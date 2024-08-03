class Solution
{
public:
    int findCheapestPrice(int n, vector<vector<int>> &arr, int src, int dst, int k)
    {
        int m = arr.size();
        unordered_map<int, list<pair<int, int>>> mp;
        queue<pair<int, pair<int, int>>> que;
        for (int i = 0; i < m; i++)
        {

            int u = arr[i][0];
            int v = arr[i][1];
            int w = arr[i][2];
            mp[u].push_back({v, w});
        }

        que.push({0, {src, 0}});
        vector<int> dist(n, 1e9);
        dist[src] = 0;
        while (!que.empty())
        {

            auto front = que.front();
            que.pop();
            int stop = front.first;
            int u = front.second.first;
            int dis = front.second.second;
            if (stop > k)
            {
                continue;
            }
            for (auto n : mp[u])
            {

                int v = n.first;
                int wgt = n.second;
                if (dis + wgt < dist[v] && stop <= k)
                {
                    dist[v] = dis + wgt;
                    que.push({stop + 1, {v, dist[v]}});
                }
            }
        }
        if (dist[dst] == 1e9)
        {
            return -1;
        }
        return dist[dst];
    }
};