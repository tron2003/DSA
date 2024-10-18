class Solution
{
public:
    int countNumbersWithUniqueDigits(int n)
    {

        if (n == 0)
        {
            return 1;
        }
        int res = 10;
        int prod = 9;
        for (int i = 2; i <= n; i++)
        {

            res += prod * (11 - i);
            prod = prod * (11 - i);
        }
        return res;
    }
};