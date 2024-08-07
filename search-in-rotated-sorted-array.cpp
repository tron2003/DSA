class Solution
{
public:
    int helper(vector<int> &arr, int low, int high, int tar)
    {

        while (low <= high)
        {

            int mid = low + (high - low) / 2;
            if (arr[mid] == tar)
            {
                return mid;
            }
            if (arr[low] <= arr[mid])
            {

                if (arr[low] <= tar && tar <= arr[mid])
                {

                    high = mid - 1;
                }
                else
                {
                    low = mid + 1;
                }
            }
            else
            {

                if (arr[high] >= tar && tar >= arr[mid])
                {
                    low = mid + 1;
                }
                else
                {
                    high = mid - 1;
                }
            }
        }
        return -1;
    }
    int search(vector<int> &arr, int tar)
    {
        int n = arr.size();
        int res = helper(arr, 0, n - 1, tar);
        return res;
    }
};