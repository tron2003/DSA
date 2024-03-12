#include <iostream>
#include <bits/stdc++.h>
using namespace std;


inline bool isfeasible(int arr[], int n, int k, int ans)
{
    int res = 1;
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        if (sum + arr[i] > ans)
        {
            res++;
            sum = arr[i];
        }
        else
        {
            sum += arr[i];
        }
    }

    return (res <= k);
}


int func(int arr[], int n, int k)
{
    int sum = 0;
    int mx = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
        mx = max(mx, arr[i]);
    }
    int low = mx, high = sum;
    int res = 0;

    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (isfeasible(arr, n, k, mid))
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

int main()
{
    int arr[] = {10, 20, 30, 40};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << func(arr, n, 2);

    return 0;
}
