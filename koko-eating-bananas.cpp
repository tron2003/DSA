class Solution
{
public:
    int func(vector<int> &arr, int mid, int n, int k)
    {

        long long total = 0;
        for (int i = 0; i < n; i++)
        {
            int temp = ceil((double)arr[i] / mid);
            total += temp;
        }
        if (total <= k)
        {
            return 1;
        }
        return 0;
    }
    int minEatingSpeed(vector<int> &arr, int k)
    {
        int l = 1;
        int n = arr.size();

        int h = 0;
        for (auto x : arr)
        {
            h = max(x, h);
        }
        int res = 0;
        while (l <= h)
        {

            int mid = l + (h - l) / 2;
            if (func(arr, mid, n, k) == 1)
            {
                res = mid;
                h = mid - 1;
            }
            else
            {

                l = mid + 1;
            }
        }
        return res;
    }
};