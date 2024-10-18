class Solution
{
public:
    long long helper(long long n)
    {

        if (n == 1)
        {
            return 1;
        }
        if (n < 0)
        {

            return INT_MAX;
        }
        long long res = INT_MAX;
        if (n % 2 == 0)
        {
            res = min(res, 1 + helper(n / 2));
        }
        if (n % 2 != 0)
        {
            res = min(res, 1 + min(helper(n - 1), helper(n + 1)));
        }
        return res;
    }
    int integerReplacement(int n)
    {

        int res = helper(n) - 1;

        return res;
    }
};