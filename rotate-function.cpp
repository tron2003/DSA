class Solution
{
public:
    int maxRotateFunction(vector<int> &arr)
    {

        int n = arr.size();
        int sum = 0;
        int f = 0;
        for (int i = 0; i < n; i++)
        {

            sum += arr[i];
            f += i * arr[i];
        }
        int res = f;
        for (int i = n - 1; i >= 0; i--)
        {
            f += sum - n * (arr[i]);
            res = max(res, f);
        }

        return res;
    }
};