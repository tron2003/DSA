class Solution
{
public:
    int singleNumber(vector<int> &arr)
    {

        int ones = 0;
        int n = arr.size();
        int twoes = 0;
        for (int i = 0; i < n; i++)
        {

            ones = (ones ^ arr[i]) & (~twoes);
            twoes = (twoes ^ arr[i]) & (~ones);
        }
        return ones;
    }
};
class Solution
{
public:
    int singleNumber(vector<int> &arr)
    {
        int res = 0;
        int n = arr.size();
        for (int i = 0; i < 32; i++)
        {
            int cnt = 0;
            for (int j = 0; j < n; j++)
            {
                if (arr[j] & (1 << i))
                {

                    cnt++;
                }
            }
            if (cnt % 3 == 1)
            {
                res = res | (1 << i);
            }
        }
        return res;
    }
};