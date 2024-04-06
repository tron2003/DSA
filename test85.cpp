#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int func(int arr[], int arr1[], int n)
{
    for (int i = 0; i < n; i++)
    {
        int curr_partrol = 0;
        int end = i;
        while (true)
        {
            curr_partrol += (arr[end] - arr1[end]);
            if (curr_partrol < 0)
            {
                break;
            }
            end = (end + 1) % n;
            if (end == i)
            {

                return (i + 1);
            }
        }
    }
    return -1;
}

int main()
{
    int arr[] = {8, 9, 4};
    int arr1[] = {5, 10, 12};
    cout << func(arr, arr1, 3);
    return 0;
}