#include <bits/stdc++.h>
int bound(vector<int> arr, int x, int m)
{

    int low = 0;
    int high = m - 1;
    int res = m;
    while (low <= high)
    {

        int mid = low + (high - low) / 2;
        if (arr[mid] > x)
        {

            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return low;
}
int helper(vector<vector<int>> &arr, int m, int n, int mid)
{

    int cnt = 0;
    for (int i = 0; i < m; i++)
    {

        cnt += bound(arr[i], mid, n);
    }
    return cnt;
}

int median(vector<vector<int>> &arr, int m, int n)
{
    // Write your code here.

    int low = INT_MAX;
    int high = INT_MIN;
    for (int i = 0; i < m; i++)
    {

        low = min(low, arr[i][0]);
        high = max(high, arr[i][n - 1]);
    }
    int req = (n * m) / 2;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        int k = helper(arr, m, n, mid);
        if (k <= req)
        {

            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return low;
}