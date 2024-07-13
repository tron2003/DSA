class Solution
{
public:
    int numberOfSubstrings(string s)
    {
        int res = 0;
        int num = 0;
        int l = 0;
        int n = s.size();
        int r = 0;
        vector<int> arr(3, -1);

        for (int i = 0; i < n; i++)
        {

            arr[s[i] - 'a'] = i;
            if (arr[0] != -1 && arr[1] != -1 && arr[2] != -1)
            {
                res += (1 + min({arr[0], arr[1], arr[2]}));
            }
        }
        return res;
    }
};