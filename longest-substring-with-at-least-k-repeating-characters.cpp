class Solution
{
public:
    int helper(string s, vector<int> &mp)
    {

        int res = 0;
        for (auto x : s)
        {

            if (mp[x - 'a'] == 0)
            {
                res++;
                mp[x - 'a'] = 1;
            }
        }
        return res;
    }
    int longestSubstring(string s, int k)
    {

        vector<int> mp(26, 0);
        int maxu = helper(s, mp);
        int res = 0;
        for (int i = 1; i <= maxu; i++)
        {

            mp = vector<int>(26, 0);
            int ws = 0;
            int we = 0;
            int cu = 0;
            int idx = 0;
            int cq = 0;
            while (we < s.size())
            {

                if (cu <= i)
                {

                    idx = s[we] - 'a';
                    if (mp[idx] == 0)
                    {
                        cu++;
                    }
                    mp[idx]++;
                    if (mp[idx] == k)
                    {
                        cq++;
                    }
                    we++;
                }
                else
                {
                    idx = s[ws] - 'a';
                    if (mp[idx] == k)
                    {
                        cq--;
                    }
                    mp[idx]--;
                    if (mp[idx] == 0)
                    {
                        cu--;
                    }
                    ws++;
                }
                if (cu == i && cu == cq)
                {
                    res = max(we - ws, res);
                }
            }
        }
        return res;
    }
};