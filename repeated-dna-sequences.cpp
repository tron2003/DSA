class Solution
{
public:
    vector<string> findRepeatedDnaSequences(string s)
    {
        if (s.size() <= 10)
        {
            return {};
        }
        vector<string> res;
        string prev = "";
        string curr = "";
        int r = 10;
        int l = 0;
        int n = s.size();

        unordered_map<string, int> mp;
        for (int i = 0; i < s.size() - 9; i++)
        {

            mp[s.substr(i, 10)]++;
        }
        for (auto x : mp)
        {

            if (x.second > 1)
            {
                res.push_back(x.first);
            }
        }
        return res;
    }
};