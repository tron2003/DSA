#define mod 100000007
class Solution
{
public:
    int check(string s)
    {

        int res = 0;
        int i = 0;
        int j = s.size();
        while (i < j)
        {
            if (s[i] == '1')
            {
                res++;
            }

            i++;
        }

        return res;
    }
    int helper(int n)
    {

        if (n < 1)
        {

            return 0;
        }
        if (n == 1)
        {

            return 1;
        }
        if (n >= 1 && n <= 9)
        {
            return 1;
        }

        // int rec = ;
        return helper(n - 1) % mod + check(to_string(n % mod));
    }

    int countDigitOne(int n)
    {
        int res = 0;
        for (long long m = 1; m <= n; m *= 10)
            res += (n / m + 8) / 10 * m + (n / m % 10 == 1) * (n % m + 1);
        return res;
    }
};