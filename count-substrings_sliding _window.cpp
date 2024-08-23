class Solution
{
public:
    int countKConstraintSubstrings(string str, int k)
    {
        int n = str.size();
        int l = 0;
        int r = 0;
        int zero = 0;
        int one = 0;
        int res = 0;
        while (r < n)
        {

            if (str[r] == '1')
            {
                one++;
            }
            else
            {
                zero++;
            }
            while (zero > k && one > k)
            {

                if (str[l] == '1')
                {
                    one--;
                }
                else
                {
                    zero--;
                }
                l++;
            }
            res += (r - l + 1);
            r++;
        }
        return res;
    }
};