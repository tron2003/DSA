#define mod 1000000007
#define p pair<long long, long long>
#define pa pair<int, pa>
class Solution
{
public:
    //    long long mod = 10e9+7;
    int countPaths(int n, vector<vector<int>> &arr)
    {
        int m = arr.size();
        unordered_map<int, list<p>> mp;
        for (int i = 0; i < arr.size(); i++)
        {

            int u = arr[i][0];
            int v = arr[i][1];
            int w = arr[i][2];
            mp[u].push_back({v, w});
            mp[v].push_back({u, w});
        }
        priority_queue<p, vector<p>, greater<p>> que;
        vector<long long> dist(n, LLONG_MAX);
        vector<long long> ways(n, 0);
        dist[0] = 0;
        ways[0] = 1;
        // ways[1]=1;
        que.push({0, 0});
        while (!que.empty())
        {
            auto front = que.top();
            long long w = front.first;
            long long u = front.second;
            que.pop();

            for (auto x : mp[u])
            {

                long long v = x.first;
                long long wgt = x.second % mod;
                if (wgt + w < dist[v])
                {

                    dist[v] = (wgt + w);
                    que.push({dist[v], v});
                    ways[v] = ways[u];
                }
                else if (wgt + w == dist[v])
                {

                    ways[v] = (ways[v] + ways[u]) % mod;
                }
            }
        }

        return (int)ways[n - 1] % mod;
    }
};