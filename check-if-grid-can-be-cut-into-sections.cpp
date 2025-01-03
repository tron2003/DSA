class Solution
{
public:
    static bool cmp(pair<int, int> &a, pair<int, int> &b)
    {
        int x = a.first;
        int y = b.first;
        if (x != y)
        {
            return x < y;
        }

        return a.second < b.second;
    }
    vector<pair<int, int>> helper(vector<pair<int, int>> &arr)
    {

        if (arr.size() <= 1)
        {
            return arr;
        }
        vector<pair<int, int>> res;

        sort(arr.begin(), arr.end(), cmp);

        res.push_back(arr[0]);
        for (int i = 1; i < arr.size(); i++)
        {

            if (arr[i].first < (res.back().second))
            {

                res.back().second = max(arr[i].second, res.back().second);
            }
            else
            {
                res.push_back(arr[i]);
            }
        }

        return res;
    }
    bool checkValidCuts(int n, vector<vector<int>> &arr)
    {

        vector<pair<int, int>> xaxis;
        vector<pair<int, int>> yaxis;
        for (auto x : arr)
        {

            xaxis.push_back({x[0], x[2]});
            yaxis.push_back({x[1], x[3]});
        }
        vector<pair<int, int>> arr1 = helper(xaxis);
        vector<pair<int, int>> arr2 = helper(yaxis);
        return arr1.size() >= 3 || arr2.size() >= 3;
    }
};