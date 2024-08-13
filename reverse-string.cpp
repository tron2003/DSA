class Solution
{
public:
    void helper(vector<char> &str, int l, int h)
    {

        if (l >= h)
        {
            return;
        }
        char temp = str[l];
        str[l] = str[h];
        str[h] = temp;
        helper(str, l + 1, h - 1);
    }
    void reverseString(vector<char> &str)
    {
        int n = str.size();
        helper(str, 0, n - 1);
        return;
    }
};