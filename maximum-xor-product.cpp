class Solution
{
public:
    int maximumXorProduct(long long a, long long b, int n)
    {

        int res = 0;
        long long mod = 1e9 + 7;
        for (int i = n - 1; i >= 0; i--)
        {

            long long mask = (long long)1 << i;
            if ((a & mask) && (b & mask))
            {
                continue;
            }
            else if ((a & mask))
            {

                if (a > b)
                {
                    a = a ^ mask;
                    b = b | mask;
                }
                continue;
            }
            else if ((b & mask))
            {

                if (b > a)
                {
                    b = b ^ mask;
                    a = a | mask;
                }
            }
            else
            {

                a ^= mask;
                b ^= mask;
            }
        }
        a = a % mod;
        b = b % mod;
        return (a * b) % mod;
    }
};