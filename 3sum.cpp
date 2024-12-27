class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &arr)
    {
        int n = arr.size();
        // int res = 0;
        vector<vector<int>> res;
        sort(arr.begin(), arr.end());
        for (int i = 0; i < n; i++)
        {
            if (i > 0 && arr[i - 1] == arr[i])
            {
                continue;
            }
            int j = i + 1;
            int k = n - 1;
            while (j < k)
            {
                int total = arr[i] + arr[j] + arr[k];
                if (total < 0)
                {

                    j++;
                }
                else if (total > 0)
                {

                    k--;
                }
                else
                {
                    res.push_back({arr[i], arr[j], arr[k]});
                    j++;
                    while (arr[j] == arr[j - 1] && j < k)
                    {
                        j++;
                    }
                }
            }
        }
        return res;
    }
};