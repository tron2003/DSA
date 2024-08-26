class Solution
{
public:
    string makedigit(int x, int y)
    {

        string s = to_string(x);
        int n = s.size();
        for (int i = 0; i < y - n; i++)
        {
            s = "0" + s;
        }
        return s;
    }
    unordered_set<string> makeswap(int num, int digit)
    {

        string s = makedigit(num, digit);
        unordered_set<string> mp;
        mp.insert(s);
        for (int i = 0; i < digit; i++)
        {
            for (int j = i + 1; j < digit; j++)
            {

                swap(s[i], s[j]);
                mp.insert(s);
                for (int i1 = 0; i1 < digit; i1++)
                {
                    for (int j1 = i1 + 1; j1 < digit; j1++)
                    {

                        if (s[i1] != s[j1])
                        {
                            swap(s[i1], s[j1]);
                            mp.insert(s);
                            swap(s[i1], s[j1]);
                        }
                    }
                }
                swap(s[i], s[j]);
            }
        }
        return mp;
    }
    int countPairs(vector<int> &arr)
    {
        int n = arr.size();
        int digit = to_string((*max_element(arr.begin(), arr.end()))).size();
        unordered_map<string, int> mp;
        int res = 0;
        for (int i = 0; i < n; i++)
        {

            for (auto x : makeswap(arr[i], digit))
            {

                if (mp.count(x) > 0)
                {
                    res += mp[x];
                }
            }
            mp[makedigit(arr[i], digit)]++;
        }
        return res;
    }
};