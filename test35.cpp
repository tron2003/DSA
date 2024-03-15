#include <iostream>
#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

int func(int arr[], int arr2[], int n)
{
    sort(arr, arr + n);
    sort(arr2, arr2 + n);
    int i = 1;
    int j = 0;
    int res = 1;
    int count = 1;
    while (i < n && j < n)
    {

        if (arr[i] <= arr2[j])
        {

            count++;
            i++;
        }
        else{
            count--;
            j++;
        }
        res=max(res,count);
    }
    return res;
}

int main()
{
    int arr[] = {900,940};
    int arr2[] = {1000,1030};

    cout<< func(arr, arr2, sizeof(arr) / sizeof(arr[0]));
    // for (auto x : arr)
    // {
    //     cout << x << " ";
    // }

    return 0;
}