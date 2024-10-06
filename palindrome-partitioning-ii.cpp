class Solution
{
public:
    unordered_map<int, int> mp;
    bool check(string s, int i, int j)
    {

        while (i < j)
        {
            if (s[i] != s[j])
            {

                return false;
            }

            i++;
            j--;
        }
        return true;
    }
    int helper(string &s, int i)
    {

        if (i >= s.size())
        {
            return 0;
        }
        if (mp.count(i))
        {
            return mp[i];
        }
        int temp = INT_MAX;
        for (int k = i; k < s.size(); k++)
        {

            if (check(s, i, k))
            {
                int res = 1 + helper(s, k + 1);
                temp = min(temp, res);
            }
        }
        return mp[i] = temp;
    }
    int minCut(string s)
    {
        int res = INT_MAX;
        //    unordered_map<int,int>mp;
        res = helper(s, 0) - 1;
        return res;
    }
};