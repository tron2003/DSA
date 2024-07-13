class Solution
{
public:
    int maximumGain(string s, int x, int y)
    {
        int n = s.size();
        string top;
        string last;
        int high = 0;
        int res = 0;
        int low = 0;
        if (x > y)
        {
            top = "ab";
            high = x;
            last = "ba";
            low = y;
        }
        else
        {

            top = "ba";
            high = y;
            last = "ab";
            low = x;
        }
        vector<char> stack;
        for (int i = 0; i < n; i++)
        {

            if (stack.empty() == false && top[0] == stack.back() && s[i] == top[1])
            {
                res += high;
                stack.pop_back();
            }
            else
            {
                stack.push_back(s[i]);
            }
        }
        // stack.clear();
        vector<char> stack1;
        for (auto x : stack)
        {

            if (stack1.empty() == false && last[0] == stack1.back() && x == last[1])
            {
                res += low;
                stack1.pop_back();
            }
            else
            {
                stack1.push_back(x);
            }
        }
        return res;
    }
};