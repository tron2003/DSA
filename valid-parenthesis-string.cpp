class Solution
{
public:
    bool checkValidString(string s)
    {

        int mn = 0;
        int mx = 0;
        int n = s.size();
        for (int i = 0; i < n; i++)
        {

            if (s[i] == '(')
            {

                mn++;
                mx++;
            }
            else if (s[i] == ')')
            {

                mn--;
                mx--;
            }
            else
            {
                mn--;
                mx++;
            }
            if (mn < 0)
            {
                mn = 0;
            }
            if (mx < 0)
            {
                return false;
            }
        }
        return mn == 0;
    }
};