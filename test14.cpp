#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int func(int arr[], int n)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
    }
    int ls = 0;
    for (int i = 0; i < n; i++)
    {
        
            sum = sum - arr[i];
        

        if (ls == sum)
        {
            return true;
        }
        
            ls += arr[i];
        
    }
    return false;
}

int main()
{
    int arr[] = {3, 4, 8, -9, 9, 7};
    cout << func(arr, sizeof(arr) / sizeof(arr[0]));

    return 0;
}