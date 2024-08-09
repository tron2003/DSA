class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &arr, int k)
    {
        int low = 0;
        int m = arr.size();

        int n = arr[0].size();
        int high = n * m - 1;
        while (low <= high)
        {

            int mid = low + (high - low) / 2;
            int row = mid / n;
            int col = mid % n;
            if (arr[row][col] == k)
            {
                return true;
            }
            else if (arr[row][col] < k)
            {

                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
        return false;
    }
};