#define pa pair<int, int>
class Solution
{
public:
    vector<int> helper(vector<vector<int>> &mp, int src, int n)
    {

        vector<int> dist(n, INT_MAX);
        priority_queue<pa, vector<pa>, greater<pa>> que;
        que.push({0, src});
        dist[src] = 0;
        while (!que.empty())
        {
            auto front = que.top();
            int dis = front.first;
            int u = front.second;
            que.pop();
            for (int i = 0; i < n; i++)
            {
                if (mp[u][i] != INT_MAX)
                {
                    int v = i;
                    int wgt = mp[u][i];
                    if (dis + wgt < dist[v])
                    {
                        dist[v] = dis + wgt;
                        que.push({dist[v], v});
                    }
                }
            }
        }

        return dist;
    }
    int findTheCity(int n, vector<vector<int>> &arr, int l)
    {

        vector<vector<int>> dist(n, vector<int>(n, INT_MAX));
        for (int i = 0; i < arr.size(); i++)
        {
            int u = arr[i][0];
            int v = arr[i][1];
            int w = arr[i][2];
            dist[u][v] = w;
            dist[v][u] = w;
        }
        for (int i = 0; i < n; i++)
        {
            dist[i][i] = 0;
        }
        for (int i = 0; i < n; i++)
        {

            dist[i] = helper(dist, i, n);
        }
        int cntcity = n;
        int res = -1;
        for (int i = 0; i < n; i++)
        {
            int cnt = 0;
            for (int j = 0; j < n; j++)
            {

                if (dist[i][j] <= l)
                {
                    cnt++;
                }
            }
            if (cnt <= cntcity)
            {

                cntcity = cnt;
                res = i;
            }
        }
        return res;
    }
};