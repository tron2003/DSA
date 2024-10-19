class Solution
{
public:
    bool helper(vector<int> &arr, int i, int a, int b, int c, int d)
    {
        if (i >= arr.size())
        {

            if (a == 0 && b == 0 && c == 0 && d == 0)
            {
                return 1;
            }
            return false;
        }

        bool res = 0;
        if (arr[i] <= a)
        {
            a = a - arr[i];
            if (helper(arr, i + 1, a, b, c, d))
            {
                return true;
            }
            a = a + arr[i];
        }
        if (arr[i] <= b)
        {
            b = b - arr[i];
            if (helper(arr, i + 1, a, b, c, d))
            {
                return true;
            }
            b = b + arr[i];
        }
        if (arr[i] <= c)
        {
            c = c - arr[i];
            if (helper(arr, i + 1, a, b, c, d))
            {
                return true;
            }
            c = c + arr[i];
        }

        if (arr[i] <= d)
        {
            d = d - arr[i];
            if (helper(arr, i + 1, a, b, c, d))
            {
                return true;
            }
            d = d + arr[i];
        }
        return false;
    }
    bool makesquare(vector<int> &arr)
    {

        int sum = accumulate(arr.begin(), arr.end(), 0);
        if (sum % 4 != 0)
        {
            return false;
        }
        int a = sum / 4;
        int b = sum / 4;
        int c = sum / 4;
        int d = sum / 4;
        sort(arr.rbegin(), arr.rend());

        int what = helper(arr, 0, a, b, c, d);
        return what;
    }
};