#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int func(int arr[], int arr1[], int n)
{

    int start = 0;
    int prev = 0;
    int curr = 0;
    for (int i = 0; i < n; i++)
    {

        curr = curr+(arr[i] - arr1[i]);
        if (curr < 0)
        {
            start = i + 1;
            prev = prev + curr;
        }
    }

    return (curr + prev) >= 0 ? (start + 1) : -1;
}

int main()
{
    int arr[] = {4, 8, 7, 4};
    int arr1[] = {6, 5, 3, 5};
    cout << func(arr, arr1, 2);
    return 0;
}