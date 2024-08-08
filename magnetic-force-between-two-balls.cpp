class Solution
{
public:
    int helper(vector<int> arr, int mid, int k)
    {

        int n = arr.size();
        int last = arr[0];
        int res = 1;
        for (int i = 1; i < n; i++)
        {

            if (abs(arr[i] - last) >= mid)
            {
                res++;
                last = arr[i];
            }
        }
        if (res >= k)
        {
            return 1;
        }
        return 0;
    }
    int maxDistance(vector<int> &arr, int k)
    {
        int n = arr.size();
        int low = 1;
        int high = INT_MIN;

        sort(arr.begin(), arr.end());
        high = arr[n - 1];
        int res = 0;
        while (low <= high)
        {

            int mid = low + (high - low) / 2;
            if (helper(arr, mid, k))
            {
                res = mid;
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
        return res;
    }
};