class Solution
{
public:
    int maxSubArray(vector<int> &arr)
    {
        int n = arr.size();

        int res = INT_MIN;
        int i = 0;
        int j = n - 1;
        int sum = 0;
        for (int i = 0; i < n; i++)
        {
            sum += arr[i];
            if (res < sum)
            {

                res = sum;
            }
            if (sum < 0)
            {
                sum = 0;
            }
        }
        return res;
    }
};