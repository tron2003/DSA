class Solution
{
public:
    double maxProbability(int n, vector<vector<int>> &arr, vector<double> &succ,
                          int start, int end)
    {

        int k = arr.size();

        priority_queue<pair<double, int>> que;
        vector<double> res(n, 0.0);
        unordered_map<int, list<pair<int, double>>> mp;
        res[start] = 1;
        for (int i = 0; i < k; i++)
        {

            auto x = arr[i][0];
            auto y = arr[i][1];
            auto w = succ[i];
            mp[x].push_back({y, w});
            mp[y].push_back({x, w});
        }

        que.push({1.0, start});

        while (!que.empty())
        {

            double pro = que.top().first;
            auto u = que.top().second;
            que.pop();
            if (u == end)
            {
                return pro;
            }
            for (auto x : mp[u])
            {

                int v = x.first;
                double w = x.second;
                double temp = pro * w;
                if (temp > res[v])
                {
                    res[v] = temp;

                    que.push({res[v], v});
                }
            }
        }
        return res[end];
    }
};