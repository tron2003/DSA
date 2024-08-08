class Solution
{
public:
    int helper(vector<int> &arr, int mid, int k)
    {

        long long sum = 0;
        for (auto x : arr)
        {

            int temp = ceil(double(x) / mid);
            sum += temp;
        }

        return sum <= k;
    }
    int smallestDivisor(vector<int> &arr, int k)
    {

        long long n = arr.size();
        int low = INT_MAX;
        int high = INT_MIN;
        long long sum = 0;
        if (arr.size() > k)
        {
            return -1;
        }
        for (auto x : arr)
        {
            sum += x;
            low = min(low, x);
            high = max(high, x);
        }
        low = 1;
        long long res = 0;
        while (low <= high)
        {

            long long mid = low + (high - low) / 2;

            if (helper(arr, mid, k) == 1)
            {
                res = mid;

                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        return res;
    }
};