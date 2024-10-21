class Solution
{
public:
    void helper(vector<int> arr, int i, int j, vector<vector<int>> &res)
    {

        if (i == j - 1)
        {
            res.push_back(arr);
            return;
        }
        for (int k = i; k < j; k++)
        {
            if (k != i && arr[i] == arr[k])
            {
                continue;
            }

            swap(arr[i], arr[k]);
            helper(arr, i + 1, j, res);
        }
    }
    vector<vector<int>> permuteUnique(vector<int> &arr)
    {

        vector<vector<int>> res;
        set<vector<int>> st;
        sort(arr.begin(),
             arr.end());
        helper(arr, 0, arr.size(), res);

        return res;
    }
};