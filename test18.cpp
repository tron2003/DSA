#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int func(int arr[], int l, int r, int x)
{
    if (l > r)
    {
        return -1;
    }

    int mid = l + (r - l) / 2;
    if (x > arr[mid])
    {
        return func(arr, mid + 1, r, x);
    }
    else if (x < arr[mid])
    {
        return func(arr, l, mid - 1, x);
    }
    else
    {

        if (mid == r-1 || arr[mid+ 1] != arr[mid])
        {
            return mid;
        }
        else{
            func(arr,mid+1,r,x);
        }
    }
}

int main()
{
    int arr[] = {1, 10, 10, 10, 20, 20, 40};
    cout << func(arr, 0, sizeof(arr) / sizeof(arr[0]), 20);
    return 0;
}