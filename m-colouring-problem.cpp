class Solution
{
public:
    bool check(unordered_map<int, list<int>> &mp, vector<int> &res, int node,
               int col)
    {
        for (auto x : mp[node])
        {

            if (res[x] == col)
            {
                return false;
            }
        }

        return true;
    }
    int solve(unordered_map<int, list<int>> &mp, int node, int n,
              vector<int> &res)
    {

        if (node == n)
        {
            return true;
        }

        for (int i = 1; i <= n; i++)
        {
            if (res[node] == -1)
            {
                if (check(mp, res, node, i))
                {
                    res[node] = i;
                    if (solve(mp, node + 1, n, res))
                    {
                        return true;
                    }
                    res[node] = -1;
                }
            }
        }
        return false;
    }
    vector<int> gardenNoAdj(int n, vector<vector<int>> &arr)
    {
        unordered_map<int, list<int>> mp;
        for (auto x : arr)
        {

            int x1 = x[0];
            int y1 = x[1];
            mp[x1 - 1].push_back(y1 - 1);
            mp[y1 - 1].push_back(x1 - 1);
        }
        vector<int> res(n, -1);

        solve(mp, 0, n, res);
        return res;
    }
};