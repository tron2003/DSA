class Solution
{
public:
    bool helper(string &temp)
    {

        int i = 0;
        int j = temp.size() - 1;
        while (i < j)
        {
            if (temp[i] != temp[j])
            {

                return false;
            }
            i++;
            j--;
        }
        return true;
    }
    int maxProduct(string s)
    {

        int n = s.size();
        unordered_map<int, int> mp;

        for (int i = 1; i < (1 << n); i++)
        {

            string temp;
            for (int j = 0; j < n; j++)
            {

                if ((1 << j) & i)
                {
                    temp += s[j];
                }
            }

            if (helper(temp))
            {
                mp[i] = temp.size();
            }
        }
        int res = 0;
        int m = mp.size();
        for (auto x : mp)
        {
            for (auto y : mp)
            {

                if ((x.first & y.first) == 0)
                {
                    res = max(res, y.second * x.second);
                }
            }
        }
        return res;
    }
};