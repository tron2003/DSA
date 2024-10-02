class Solution
{
public:
    bool helper(vector<int> &arr, int mid, int n)
    {

        int res = 0;
        for (auto x : arr)
        {

            res += (x - 1) / mid + 1;
            if (res > n)
                return false;
        }
        return true;
    }
    int minimizedMaximum(int n, vector<int> &arr)
    {
        int i = 1;
        int j = 0;
        for (auto x : arr)
        {
            j = max(x, j);
        }
        int res = -1;
        while (i <= j)
        {

            int mid = j + (i - j) / 2;
            if (helper(arr, mid, n))
            {

                res = mid;
                j = mid - 1;
            }
            else
            {

                i = mid + 1;
            }
        }
        return res;
    }
};