class Solution
{
public:
    int candy(vector<int> &arr)
    {
        int n = arr.size();
        int sum = 1, i = 1;
        while (i < n)
        {

            if (arr[i] == arr[i - 1])
            {
                sum = sum + 1;
                i++;
                continue;
            }
            int peak = 1;
            while (i < n && arr[i - 1] < arr[i])
            {
                peak++;
                sum += peak;
                i++;
            }
            int down = 1;
            while (i < n && arr[i - 1] > arr[i])
            {
                sum += down;
                down++;
                i++;
            }
            if (down > peak)
            {
                sum += down - peak;
            }
        }
        return sum;
    }
};