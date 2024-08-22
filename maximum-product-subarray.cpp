class Solution
{
public:
    int maxProduct(vector<int> &arr)
    {
        int n = arr.size();
        int pre = 1;
        int suf = 1;
        int res = INT_MIN;
        for (int i = 0; i < n; i++)
        {
            if (arr[i] < 0)
            {
                swap(pre, suf);
            }
            pre = max(arr[i], pre * arr[i]);
            suf = min(arr[i], suf * arr[i]);
            res = max(res, pre);
        }
        return res;
    }
};