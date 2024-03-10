#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int func1(int arr[], int n)
{

    int res = arr[0];
    int curr = arr[0];

    for (int i = 1; i < n; i++)
    {
        curr = max(curr + arr[i], arr[i]);
        res = max(curr, res);
    }
    return res;
}
int ar=0;
int func2(int arr[], int n)
{
    int max_normal = func1(arr, n);
    if (max_normal < 0)
    {
        return max_normal;
    }
    int arr_sum = 0;

    for (int i = 0; i < n; i++)
    {

        arr_sum += arr[i];
        arr[i] =(-arr[i]);
    }
    ar=arr_sum;
    int max_cir = arr_sum+func1(arr,n);



return max(max_cir,max_normal);}



int main()
{

    int arr[] = {8, -4, 3, -5, 4};
    cout << func1(arr,5) << " ";

    return 0;
}