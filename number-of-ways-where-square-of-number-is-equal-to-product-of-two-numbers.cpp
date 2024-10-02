class Solution
{
public:
    int helper(vector<int> &arr1, vector<int> &arr2)
    {

        int res = 0;

        unordered_map<int, int> mp;
        for (int x : arr2)
        {

            mp[x]++;
        }
        for (auto x : arr1)
        {

            long long temp = (long long)x * x;
            for (auto [k, temp2] : mp)
            {

                if (temp % k > 0 || mp.find(temp / k) == mp.end())
                {
                    continue;
                }
                if (temp / k == k)
                {
                    res += temp2 * (temp2 - 1);
                }
                else
                {
                    res += temp2 * mp[temp / k];
                }
            }
        }

        return res / 2;
    }

    int numTriplets(vector<int> &arr1, vector<int> &arr2)
    {
        int m = arr1.size();
        int n = arr2.size();
        return helper(arr1, arr2) + helper(arr2, arr1);
    }
};