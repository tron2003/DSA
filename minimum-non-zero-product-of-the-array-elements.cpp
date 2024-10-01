#define mod 1000000007
class Solution
{
public:
    int power(long long x, long long p)
    {

        if (p == 0)
        {
            return 1;
        }
        long long temp = power(x, p / 2);
        temp = (temp * temp) % mod;
        if (p % 2 == 1)
        {
            temp = (temp * (x % mod)) % mod;
        }
        return temp % mod;
    }
    int minNonZeroProduct(int p)
    {
        if (p == 1)
        {
            return 1;
        }
        if (p == 0)
        {
            return 0;
        }
        long long temp = ((long long)1 << p) - 1;

        return temp % mod * power(temp - 1, temp / 2) % mod;
    }
};