class Solution
{
public:
    int divide(int divid, int div)
    {
        if (divid == div)
        {
            return 1;
        }
        if (divid == INT_MIN && div == -1)
            return INT_MAX;
        if (divid == INT_MIN && div == 1)
            return INT_MIN;

        long long n = abs(divid);
        long long d = abs(div);
        int res = 0;
        while (n >= d)
        {

            long int mul = d, tmp = 1;
            while (mul <= n - mul)
            {
                mul += mul;
                tmp += tmp;
            }
            res += tmp;
            n -= mul;
        }
        if ((divid < 0 && div > 0) || (divid > 0 && div < 0))
            return -res;

        return res;
    }
};