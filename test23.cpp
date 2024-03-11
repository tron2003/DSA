#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int func(int arr[], int n)
{
    int low = 0;
    int high = n - 1;
    while (low <= high)
    {
        int mid = (high + low) / 2;
        if ((mid == 0 || arr[mid - 1] <= arr[mid]) && (mid == n - 1 || (arr[mid + 1] <= arr[mid])))
        {
            return mid;
        }
        if (mid > 0 && arr[mid - 1] >= arr[mid])
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return -1;
}

int main()
{
    int arr[] = {5, 10, 20, 100, 7};
    cout << func(arr, 5);
    return 0;
}