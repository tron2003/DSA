class Solution
{
public:
    vector<vector<int>> insert(vector<vector<int>> &arr, vector<int> &arr1)
    {

        int i = 0;
        vector<vector<int>> res;
        int n = arr.size();
        int start = arr1[0];

        int end = arr1[1];
        while (i < n && arr[i][1] < start)
        {

            res.push_back(arr[i]);
            i++;
        }

        while (i < n && arr[i][0] <= end)
        {
            start = min(start, arr[i][0]);
            end = max(end, arr[i][1]);
            i++;
        }
        res.push_back({start, end});
        while (i < n)
        {
            res.push_back(arr[i]);
            i++;
        }

        return res;
    }
};