class Solution
{
public:
    int helper(vector<vector<int>> arr, int mid)
    {

        int idx = -1;
        int temp = -1;
        int m = arr.size();
        for (int i = 0; i < m; i++)
        {
            if (arr[i][mid] > temp)
            {

                temp = arr[i][mid];
                idx = i;
            }
        }
        return idx;
    }
    vector<int> findPeakGrid(vector<vector<int>> &arr)
    {
        int m = arr.size();
        int n = arr[0].size();
        int low = 0;
        int high = n - 1;
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            int k = helper(arr, mid);
            int left = mid - 1 >= 0 ? arr[k][mid - 1] : -1;
            int right = mid + 1 < n ? arr[k][mid + 1] : -1;
            if (left < arr[k][mid] && arr[k][mid] > right)
            {

                return {k, mid};
            }
            else if (arr[k][mid] < left)
            {

                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        return {-1, -1};
    }
};