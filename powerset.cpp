class Solution
{
public:
    vector<vector<int>> subsets(vector<int> &arr)
    {
        int n = arr.size();
        int sub = 1 << n;
        vector<vector<int>> res;
        for (int i = 0; i < (sub - 1); i++)
        {
            vector<int> temp;
            for (int j = 0; j <= n - 1; j++)
            {

                if (i & (1 << j))
                {

                    temp.push_back(arr[j]);
                }
            }
            res.push_back(temp);
        }
        res.push_back(arr);
        return res;
    }
};