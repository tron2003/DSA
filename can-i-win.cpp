class Solution
{
public:
    bool helper(int range, int tar, int use, int sum, unordered_map<int, int> &mp)
    {

        if (sum >= tar)
        {
            return false;
        }
        if (mp.find(use) != mp.end())
        {
            return mp[use];
        }
        for (int i = 1; i <= range; i++)
        {

            int mask = 1 << i;
            if (!(use & mask))
            {

                if (helper(range, tar, use | mask, sum + i, mp) == false)
                {

                    return mp[use] = true;
                }
            }
        }
        return mp[use] = false;
    }
    bool canIWin(int range, int tar)
    {
        int sum = range * (range + 1) / 2;

        if (sum < tar)
        {
            return 0;
        }
        if (tar <= 0)
        {
            return 1;
        }
        unordered_map<int, int> dp;
        return helper(range, tar, 0, 0, dp);
    }
};