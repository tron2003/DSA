
class Solution
{
public:
    int ans = 0;
    int path = 1e9;
    vector<int> visited, a;
    int par_cost[50007];
    vector<array<int, 2>> adj[50007];
    vector<int> dup[50007];
    void helper(int u, int p, int l = 0, int len = 0, int w = 0, int depth = 0,
                int max_valid = 0)
    {

        len += w;
        visited.push_back(len);
        int last = -1;
        if (dup[a[u]].size() != 0)
        {
            last = max(dup[a[u]].back(), max_valid - 1);
        }
        max_valid = max(max_valid, last + 1);
        int sum = visited.back() - visited[max_valid];
        if (ans < sum)
        {
            path = visited.size() - max_valid;
            ans = sum;
        }
        else if (ans == sum)
        {
            path = min(path, (int)visited.size() - max_valid);
        }
        dup[a[u]].push_back(depth);
        for (auto [v, tw] : adj[u])
        {
            if (v == p)
            {
                continue;
            }
            par_cost[v] = tw;
            helper(v, u, l, len, tw, depth + 1, max_valid);
        }
        dup[a[u]].pop_back();
        visited.pop_back();
    }

    vector<int> longestSpecialPath(vector<vector<int>> &arr,
                                   vector<int> &temp)
    {

        int n = arr.size();
        a = temp;
        for (auto c : arr)
        {
            adj[c[0]].push_back({c[1], c[2]});
            adj[c[1]].push_back({c[0], c[2]});
        }

        helper(0, 0);

        return {ans, path};
    }
};