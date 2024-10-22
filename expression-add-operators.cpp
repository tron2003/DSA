class Solution
{
public:
    void helper(int i, string temp, long curr, long prev, string num,
                int tar, vector<string> &res)
    {

        if (i == num.size())
        {

            if (curr == tar)
            {
                res.push_back(temp);
            }
            return;
        }
        for (int j = i; j < num.size(); j++)
        {
            if (j > i && num[i] == '0')
            {

                break;
            }
            long number = stol(num.substr(i, j - i + 1));
            string s = num.substr(i, j - i + 1);
            if (i == 0)
            {
                helper(j + 1, s, number, number, num, tar, res);
            }
            else
            {
                helper(j + 1, temp + '+' + s, curr + number, number, num, tar, res);
                helper(j + 1, temp + '-' + s, curr - number, -number, num, tar, res);
                helper(j + 1, temp + '*' + s, curr - prev + (prev * number),
                       prev * number, num, tar, res);
            }
        }
    }
    vector<string> addOperators(string num, int tar)
    {
        vector<string> res;
        helper(0, "", 0, 0, num, tar, res);
        return res;
    }
};