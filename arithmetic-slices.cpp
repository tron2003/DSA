class Solution
{
public:
    int helper(vector<int> &arr, int i, int &sum)
    {

        if (i < 2)
        {
            return 0;
        }
        int temp = 0;
        if (arr[i] - arr[i - 1] == arr[i - 1] - arr[i - 2])
        {

            temp = 1 + helper(arr, i - 1, sum);
            sum += temp;
        }
        else
        {

            helper(arr, i - 1, sum);
        }

        return temp;
    }

    int numberOfArithmeticSlices(vector<int> &arr)
    {
        int n = arr.size();

        int res = 0;
        helper(arr, n - 1, res);
        return res;
    }
};