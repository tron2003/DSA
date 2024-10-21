class Solution
{
public:
    void helper(vector<int> &arr, int i, vector<vector<int>> &res,
                vector<int> temp)
    {
        if (i >= arr.size())
        {

            res.push_back(arr);
            return;
        }

        for (int k = i; k < arr.size(); k++)
        {
            swap(arr[i], arr[k]);
            helper(arr, i + 1, res, temp);
            swap(arr[k], arr[i]);
        }
    }
    vector<vector<int>> permute(vector<int> &arr)
    {

        vector<vector<int>> res;
        vector<int> temp;

        helper(arr, 0, res, temp);
        return res;
    }
};