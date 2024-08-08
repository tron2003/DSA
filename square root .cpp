#define mod 1000000009
class Solution
{
public:
    int mySqrt(int x)
    {
        if (x == 0)
        {
            return 0;
        }
        int l = 1;
        int h = x;
        long long res = 0;
        while (l <= h)
        {

            long long mid = l + (h - l) / 2;
            long long temp = (mid) * (mid);
            if (temp == x)
            {
                return mid;
            }
            if (temp < x)
            {
                res = mid;
                l = mid + 1;
            }
            else
            {
                h = mid - 1;
            }
        }

        return res;
    }
};