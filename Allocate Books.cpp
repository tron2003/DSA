bool ischeck(vector<int> &arr, int n, int m, int mid)
{

    int count = 1;
    int sum = 0;
    for (int i = 0; i < n; i++)
    {

        if (sum + arr[i] <= mid)
        {

            sum += arr[i];
        }
        else
        {

            count++;
            // if (count > m||arr[i]>mid ) {

            //   return false;
            // }
            sum = arr[i];
        }
    }
    return count <= m ? true : false;
}

int findPages(vector<int> &arr, int n, int m)
{
    // Write your code here.
    int l = 0;
    int h = 0;
    if (m > n)
    {

        return -1;
    }
    for (int i = 0; i < n; i++)
    {

        h += arr[i];
        l = max(l, arr[i]);
    }
    int res = -1;
    while (l <= h)
    {
        int mid = l + (h - l) / 2;
        if (ischeck(arr, n, m, mid))
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