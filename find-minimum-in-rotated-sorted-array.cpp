class Solution
{
public:
    int helper(vector<int> &arr, int n)
    {

        int low = 0;
        int high = n - 1;
        int res = INT_MAX;
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            if (arr[low] <= arr[high])
            {

                res = min(arr[low], res);
                break;
            }
            if (arr[low] <= arr[mid])
            {
                res = min(res, arr[low]);
                low = mid + 1;
            }
            else
            {
                res = min(res, arr[mid]);
                high = mid;
            }
        }
        return res;
    }
    int findMin(vector<int> &arr)
    {
        int n = arr.size();
        int res = helper(arr, n);
        return res;
    }
};