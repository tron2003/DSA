class Solution
{
public:
    void helper(int i, string s, unordered_set<string> &mp, string temp)
    {
        if (i >= s.size())
        {

            if (mp.find(temp) == mp.end())
            {

                mp.insert(temp);
                return;
            }
            return;
        }
        helper(i + 1, s, mp, temp + s[i]);
        helper(i + 1, s, mp, temp);

        return;
    }
    void helper2(int i, string s, set<string> &st, string temp)
    {

        if (i >= s.size())
        {
            st.insert(s);
            return;
        }

        for (int j = i; j < s.size(); j++)
        {
            swap(s[i], s[j]);
            helper2(i + 1, s, st, temp);
            swap(s[j], s[i]);
        }
        return;
    }
    int numTilePossibilities(string s)
    {

        unordered_set<string> mp;
        helper(0, s, mp, "");
        int res = 0;
        set<string> st;
        for (auto x : mp)
        {

            helper2(0, x, st, "");
        }
        return st.size() - 1;
    }
};