class Solution
{
public:
    void helper(int i, int j, int sum, int count, int tar,
                vector<vector<int>> &res, vector<int> &temp)
    {

        if (sum == tar && j == count)
        {

            res.push_back(temp);
            return;
        }
        if (i > 9)
        {

            return;
        }

        if (j > count)
        {
            return;
        }
        if (sum > tar)
        {
            return;
        }

        sum += i;
        j++;
        temp.push_back(i);
        helper(i + 1, j, sum, count, tar, res, temp);
        sum -= i;
        j--;
        temp.pop_back();
        helper(i + 1, j, sum, count, tar, res, temp);
        return;
    }
    vector<vector<int>> combinationSum3(int count, int tar)
    {

        vector<vector<int>> res;
        vector<int> temp;

        helper(1, 0, 0, count, tar, res, temp);

        return res;
    }
};