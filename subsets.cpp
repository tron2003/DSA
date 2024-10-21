class Solution
{
public:
    void helper(int i, vector<int> &arr, vector<int> &temp,
                vector<vector<int>> &res)
    {

        if (i >= arr.size())
        {
            res.push_back(temp);
            return;
        }
        temp.push_back(arr[i]);
        helper(i + 1, arr, temp, res);
        temp.pop_back();
        helper(i + 1, arr, temp, res);
    }
    vector<vector<int>> subsets(vector<int> &arr)
    {

        vector<vector<int>> res;
        vector<int> temp;

        helper(0, arr, temp, res);
        return res;
    }
};