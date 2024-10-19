class Solution
{
public:
    int getMaxRepetitions(string s1, int n1, string s2, int n2)
    {
        int c1 = 0, c2 = 0, i = 0, j = 0, n = s1.size(), m = s2.size();
        while (c1 < n1)
        {
            if (s1[i] == s2[j])
            {

                j++;
            }
            i++;
            if (i == n)
            {
                i = 0, c1++;
            }
            if (j == m)
            {
                j = 0, c2++;
            }
        }
        return c2 / n2;
    }
};