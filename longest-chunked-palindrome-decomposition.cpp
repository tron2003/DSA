class Solution
{
public:
    int longestDecomposition(string s)
    {
        int i = 0;
        int n = s.size();
        int j = n - 1;
        int last = n;

        int res = 0;

        while (i <= j && (j >= n / 2))
        {

            if (i == j)
            {

                res++;
                break;
            }
            if (s[i] == s[j])
            {

                int x = i;
                int y = j;
                int flag = 0;
                while (y < last)
                {

                    if (s[x] != s[y])
                    {
                        flag = 1;
                        break;
                    }
                    x++;
                    y++;
                }
                if (flag == 0)
                {

                    res += 2;
                    i = x;
                    last = j;
                }
            }
            j--;
        }
        if (i < n / 2 && j < n / 2)
        {

            return res + 1;
        }
        return res;
    }
};