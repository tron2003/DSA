
int helper(vector<int> &arr, int mid, int k)
{

    int count = 1;
    int temp = 0;
    for (auto x : arr)
    {
        if (temp + x <= mid)
        {
            temp += x;
        }
        else
        {
            count++;
            if (count > k || x > mid)
            {

                return 0;
            }
            temp = x;
        }
    }
    return count <= k;
}
int findLargestMinDistance(vector<int> &arr, int k)
{
    //    Write your code here.

    int n = arr.size();
    int low = -100000;
    int high = 0;
    for (auto x : arr)
    {
        low = max(x, low);
        high += x;
    }
    int res = -1;
    if (k > n)
    {
        return -1;
    }
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        int temp = helper(arr, mid, k);
        if (temp == 1)
        {
            res = mid;
            high = mid - 1;
        }
        else
        {

            low = mid + 1;
        }
    }
    return res;
}