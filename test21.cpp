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

    if (arr[mid] == x)
    {
        return mid;
    }
    else if (x > arr[mid])
    {
        return func(arr, mid + 1, r, x);
    }
    else
    {
        return func(arr, l, mid - 1, x);
    }
}

int func2(int arr[], int x)
{
    if (arr[0] == x)
    {
        return 0;
    }
    int i = 1;
    while ( arr[i] <= x)
    {
        i *= 2;
    }

    return func(arr, i / 2,i-1, x);
}

int main()
{
    int arr[] = {1, 10, 10, 10, 20, 20, 40};
    cout << func2(arr, 20);
    return 0;
}