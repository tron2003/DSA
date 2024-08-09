class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &arr, int k)
    {
        int m = arr.size();
        int n = arr[0].size();
        int row = 0;
        int col = n - 1;
        while (row < m && col >= 0)
        {

            if (arr[row][col] == k)
            {
                return 1;
            }
            else if (arr[row][col] < k)
            {

                row++;
            }
            else
            {
                col--;
            }
        }
        return 0;
    }
};