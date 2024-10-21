class Solution
{
private:
    void f(int index, vector<int> &arr, vector<int> &t,
           vector<vector<int>> &ans)
    {
        ans.push_back(t);

        for (int k = index; k < arr.size(); k++)
        {

            if (index != k && arr[k] == arr[k - 1])
            {
                continue;
            }
            t.push_back(arr[k]);
            f(k + 1, arr, t, ans);
            t.pop_back();
        }
    }

public:
    vector<vector<int>> subsetsWithDup(vector<int> &nums)
    {
        vector<vector<int>> ans;
        vector<int> t;

        sort(nums.begin(), nums.end());
        f(0, nums, t, ans);
        return ans;
    }
};
