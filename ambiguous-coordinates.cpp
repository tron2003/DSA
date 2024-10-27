class Solution
{
public:
    vector<string> helper(string s)
    {

        int n = s.size();
        if (n == 0 || (n > 1 && s[0] == '0' && s[n - 1] == '0'))
        {
            return {};
        }
        if (n > 1 && s[0] == '0')
        {
            return {"0." + s.substr(1)};
        }
        if (n == 1 || s[n - 1] == '0')
        {
            return {s};
        }
        vector<string> res = {s};
        for (int i = 1; i < n; i++)
        {
            res.push_back(s.substr(0, i) + "." + s.substr(i));
        }
        return res;
    }
    vector<string> ambiguousCoordinates(string s)
    {

        int n = s.size();
        vector<string> res;
        for (int i = 1; i < n - 2; i++)
        {

            vector<string> a = helper(s.substr(1, i));
            vector<string> b = helper(s.substr(i + 1, n - 2 - i));
            for (auto x : a)
            {

                for (auto y : b)
                {
                    res.push_back("(" + x + ", " + y + ")");
                }
            }
        }

        return res;
    }
};