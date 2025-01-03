class Solution
{
public:
    vector<int> partitionLabels(string s)
    {
        vector<int> res;
        vector<int> temp(26, 0);
        int n = s.size();
        for (int i = 0; i < n; i++)
        {

            temp[s[i] - 'a'] = i;
        }
        int l = 0;
        int r = 0;
        for (int i = 0; i < n; i++)
        {

            r = max(r, temp[s[i] - 'a']);
            if (i == r)
            {

                res.push_back(r - l + 1);
                l = r + 1;
            }
        }
        return res;
    }
};