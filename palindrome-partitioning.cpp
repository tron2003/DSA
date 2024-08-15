class Solution
{
public:
    bool check(string str, int l, int h)
    {

        while (l < h)
        {
            if (str[l] != str[h])
            {
                return false;
            }
            l++;
            h--;
        }
        return true;
    }
    void helper(vector<vector<string>> &res, vector<string> &temp, string str,
                int i)
    {

        if (i == str.size())
        {
            res.push_back(temp);
            return;
        }
        for (int k = i; k < str.size(); k++)
        {

            if (check(str, i, k))
            {
                temp.push_back(str.substr(i, k - i + 1));
                helper(res, temp, str, k + 1);
                temp.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s)
    {
        vector<vector<string>> res;
        vector<string> temp;
        helper(res, temp, s, 0);
        return res;
    }
};