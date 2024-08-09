

int helper(vector<int> &arr, int n, int x)
{

    int low = 0;
    int high = n - 1;
    int res = n;
    while (low <= high)
    {

        int mid = low + (high - low) / 2;
        if (arr[mid] >= x)
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

int rowWithMax1s(vector<vector<int>> &arr, int m, int n)
{

    int res = 0;
    int idx = -1;

    for (int i = 0; i < m; i++)
    {

        // int n = arr[i].size();
        int temp = n - helper(arr[i], n, 1);
        if (temp > res)
        {

            res = temp;
            idx = i;
        }
    }
    return idx;
}