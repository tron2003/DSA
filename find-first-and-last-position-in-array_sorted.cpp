class Solution
{
public:
    void helper1(vector<int> &arr, int low, int high, int &first, int x)
    {

        if (low > high)
        {
            return;
        }
        int mid = low + (high - low) / 2;
        if (arr[mid] >= x)
        {

            if (arr[mid] == x)
            {

                first = mid;
            }
            // first

            helper1(arr, low, mid - 1, first, x);
        }
        else
        {
            helper1(arr, mid + 1, high, first, x);
        }
    }
    void helper2(vector<int> &arr, int low, int high, int &second, int x)
    {

        if (low > high)
        {
            return;
        }
        int mid = low + (high - low) / 2;
        if (arr[mid] > x)
        {

            second = mid;
            helper2(arr, low, mid - 1, second, x);
        }
        else
        {
            helper2(arr, mid + 1, high, second, x);
        }
    }
    vector<int> searchRange(vector<int> &arr, int x)
    {
        int n = arr.size();
        int first = n;
        int second = n;
        helper1(arr, 0, n - 1, first, x);
        helper2(arr, 0, n - 1, second, x);
        if (first == n || arr[first] != x)
        {
            return {-1, -1};
        }
        return {first, second - 1};
    }
};