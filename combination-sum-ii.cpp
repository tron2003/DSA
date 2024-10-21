class Solution
{
public:
    bool helper(vector<int> &arr, int i, int sum, int tar,
                vector<vector<int>> &res, vector<int> temp)
    {

        if (tar == sum)
        {

            res.push_back(temp);
            return true;
        }
        if (i >= arr.size())
        {
            return false;
        }
        if (sum > tar)
        {
            return false;
        }

        for (int k = i; k < arr.size(); k++)
        {
            if (k > i && arr[k] == arr[k - 1])
                continue;

            if (sum + arr[k] > tar)
                break;

            temp.push_back(arr[k]);
            sum += arr[k];

            helper(arr, k + 1, sum, tar, res, temp);

            temp.pop_back();
            sum -= arr[k];
        }
        return false;
    }
    vector<vector<int>> combinationSum2(vector<int> &arr, int tar)
    {
        vector<vector<int>> res;
        vector<int> temp;
        sort(arr.begin(), arr.end());
        helper(arr, 0, 0, tar, res, temp);

        return res;
    }
};