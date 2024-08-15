class Solution
{
public:
    bool canJump(vector<int> &arr)
    {
        int n = arr.size();
        int max1 = 0;
        for (int i = 0; i < n; i++)
        {

            if (i > max1)
            {
                return false;
            }
            max1 = max(max1, i + arr[i]);
        }
        return true;
    }
};