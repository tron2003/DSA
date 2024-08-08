class Solution
{
public:
    int helper(vector<int> &arr, int mid, int m, int k, int n)
    {

        int temp = 0;
        int temp2 = 0;

        for (auto x : arr)
        {

            if (x <= mid)
            {
                temp++;
            }
            else
            {
                temp = 0;
            }
            if (temp == k)
            {

                temp = 0;
                temp2++;
            }
        }
        if (temp2 >= m)
        {
            return 1;
        }
        return 0;
    }
    int minDays(vector<int> &arr, int m, int k)
    {  
        int n = arr.size();
        if(n<m*k){
            return -1;
        }
        int h = 0;
        int l = 0;
        for (auto x : arr)
        {
            l = min(l, x);
            h = max(h, x);
        }

        int res = -1;
        while (l <= h)
        {

            int mid = l + (h - l) / 2;
            if (helper(arr, mid, m, k, n) == 1)
            {

                res = mid;
                h = mid - 1;
            }
            else
            {

                l = mid + 1;
            }
        }
        return res;
    }
};