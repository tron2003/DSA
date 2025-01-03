class Solution
{
public:
    bool containsNearbyDuplicate(vector<int> &arr, int k)
    {
        int res = 0;
        int l = 0;
        int r = 0;
        int n = arr.size();
        unordered_map<int, int> mp;
        while (l < n)
        {

            int val = arr[l];
            if (mp.find(val) != mp.end() && (l - mp[val] <= k))
            {
                return 1;
            }
            mp[val] = l;
            l++;
        }
        return false;
    }
};