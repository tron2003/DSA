#include <bits/stdc++.h>

int merge(vector<long long> &arr, int l, int mid, int h)
{

    int left = l;
    int right = mid + 1;
    vector<int> temp;
    long long cnt = 0;
    while (left <= mid && right <= h)
    {

        if (arr[left] <= arr[right])
        {

            temp.push_back(arr[left++]);
        }
        else
        {
            cnt += (mid - left) + 1;
            temp.push_back(arr[right++]);
        }
    }
    while (left <= mid)
    {

        temp.push_back(arr[left++]);
    }
    while (right <= h)
    {

        temp.push_back(arr[right++]);
    }
    for (int i = l; i <= h; i++)
    {

        arr[i] = temp[i - l];
    }
    return cnt;
}
int helper(vector<long long> &arr, int l, int h)
{

    long long cnt = 0;
    if (l >= h)
    {
        return cnt;
    }

    int mid = l + (h - l) / 2;
    cnt += helper(arr, l, mid);
    cnt += helper(arr, mid + 1, h);
    cnt += merge(arr, l, mid, h);
    return cnt;
}

long long getInversions(long long *arr1, int n)
{
    // Write your code here.
    vector<long long> arr(arr1, arr1 + n);
    long long cnt = helper(arr, 0, n - 1);
    return cnt;
}