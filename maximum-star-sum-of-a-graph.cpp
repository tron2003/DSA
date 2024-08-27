class Solution
{
public:
    int maxStarSum(vector<int> &val, vector<vector<int>> &arr, int k)
    {

        int n = val.size();
        vector<vector<pair<int, int>>> mp(n);
        for (auto arr1 : arr)
        {

            auto x = arr1[0];
            auto y = arr1[1];
            auto xval = val[x];
            auto yval = val[y];
            mp[x].push_back({yval, y});
            mp[y].push_back({xval, x});
        }
        int res = INT_MIN;
        for (int node = 0; node < n; node++)
        {

            sort(mp[node].begin(), mp[node].end());
            int c = mp[node].size();
            int sum = val[node];
            for (int x = c - 1; x >= 0 && x >= (c - k); x--)
            {

                auto y = mp[node][x].first;
                if (y < 0)
                {
                    break;
                }
                sum += y;
            }
            res = max(res, sum);
        }

        return res;
    }
};