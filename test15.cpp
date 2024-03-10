#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int func(int arr[], int arr2[], int n)
{
    int res[101] = {0};
    for (int i = 0; i < n; i++)
    {

        res[arr[i]]++;
        res[arr2[i] + 1]--;
    }
    int count = 0;
    for (int i =1; i < 101; i++)
    {

        res[i] = res[i - 1] + res[i];
        if (res[i] > res[count])
        {
            count = i;
        }
    }

    return count;
}

int main()
{
    int arr[] = {1, 2, 4};
    int arr2[] = {4, 5, 6};
    cout << func(arr, arr2, sizeof(arr) / sizeof(arr[0]));

    return 0;
}