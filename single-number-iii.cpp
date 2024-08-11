class Solution
{
public:
    vector<int> singleNumber(vector<int> &arr)
    {
        long n = arr.size();
        long temp1 = 0;
        for (int i = 0; i < n; i++)
        {
            temp1 = temp1 ^ arr[i];
        }
        long temp2 = (temp1 & temp1 - 1) ^ temp1;
        int res1 = 0;
        int res2 = 0;
        for (int i = 0; i < n; i++)
        {

            if (arr[i] & temp2)
            {
                res1 ^= arr[i];
            }
            else
            {
                res2 ^= arr[i];
            }
        }
        return {res1, res2};
    }
};