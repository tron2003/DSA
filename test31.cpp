#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int m = 3;
    int n = 7;
    int arr[] = {7,3,1,8,9,12,56};
    if (m > n)
    {
        return -1;
    }
    sort(arr, arr + n);
    int res = arr[m-1]-arr[0];

    for (int i = 1; (i+m-1) < n; i++)
    {

        res = min(res,  arr[i+m-1]-arr[i]);
    }
    cout << res;

    return 0;
}