class Solution
{
public:
    int singleNumber(vector<int> &arr)
    {

        int n = arr.size();
        int res = arr[0];
        for (int i = 1; i < n; i++)
        {
            res = res ^ arr[i];
        }
        return res;
    }
};