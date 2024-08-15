class Solution
{
public:
    int jump(vector<int> &arr)
    {
        int n = arr.size();
        int l = 0;
        int r = 0;
        long long res = 0;
        while (r < n - 1)
        {
            int far = 0;
            for (int i = l; i <= r; i++)
            {

                far = max(far, i + arr[i]);
            }
            l = r + 1;
            r = far;
            res++;
        }
        return res;
    }
};