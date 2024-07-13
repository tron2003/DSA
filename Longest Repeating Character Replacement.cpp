class Solution
{
public:
    int characterReplacement(string s, int k)
    {
        int n = s.size();
        int l = 0;
        int r = 0;
        int maxf = 0;
        int res = 0;
        vector<int> arr(26, 0);
        while (r < n)
        {

            arr[s[r] - 'A']++;
            maxf = max(maxf, arr[s[r] - 'A']);
            if ((r - l + 1) - maxf > k)
            {

                arr[s[l] - 'A']--;
                maxf = 0;

                l++;
            }
            if ((r - l + 1) - maxf <= k)
            {
                res = max(res, r - l + 1);
            }
            r++;
        }
        return res;
    }
};