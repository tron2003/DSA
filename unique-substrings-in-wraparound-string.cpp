class Solution
{
public:
    int findSubstringInWraproundString(string s)
    {
        int prev = 1;
        int curr = 1;
        vector<int> dp(26, 0);

        dp[s[0] - 'a'] = 1;
        for (int i = 1; i < s.size(); i++)
        {

            if ((s[i - 1] - 'a' + 1) % 26 == s[i] - 'a')
            {
                prev++;
            }
            else
            {
                prev = 1;
            }
            if (dp[s[i] - 'a'] < prev)
            {
                curr += prev - dp[s[i] - 'a'];
                dp[s[i] - 'a'] = prev;
            }
        }
        return curr;
    }
};