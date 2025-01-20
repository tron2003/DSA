class Solution
{
public:
    vector<int> helper(string s)
    {
        int n = s.size();
        int l = 0;

        int r = 0;
        vector<int> z(n, 0);
        for (int i = 1; i < n; i++)
        {

            if (i < r)
            {
                z[i] = min(r - i, z[i - l]);
            }
            while (i + z[i] < n && s[z[i]] == s[i + z[i]])
            {

                z[i]++;
            }
            if (i + z[i] > r)
            {
                l = i;
                r = i + z[i];
            }
        }
        return z;
    }

    int minimumTimeToInitialState(string s, int k)
    {
        int res = 1;
        int n = s.size();
        auto z = helper(s);
        for (; k * res < n; res++)
        {
            if (z[k * res] >= n - k * res)
            {
                break;
            }
        }
        return res;
    }
};