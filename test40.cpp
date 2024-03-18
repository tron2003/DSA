#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void func1(int arr[], int n, int exp)
{
    int count[10]={0};
    for (int i = 0; i < 10; i++)
    {
        count[i] = 0;
    }
    for (int i = 0; i < n; i++)
    {

        count[(arr[i]/exp)%10]++;
    }

    for (int i = 1; i < n; i++)
    {
        count[i] = count[i - 1] + count[i];
    }
    int temp[n];
    for (int i = n - 1; i >= 0; i--)
    {

        temp[count[(arr[i]/exp)%10] - 1] = arr[i];
        count[(arr[i]/exp)%10]--;
    }
    for (int i = 0; i < n; i++)
    {

        arr[i] = temp[i];
    }
}

void func(int arr[], int n)
{

    int mx = arr[0];
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > mx)
        {
            mx = arr[i];
        }
    }
    for (int exp = 1; mx/exp > 0; exp = exp * 10)
    {

        func1(arr, n, exp);
    }
}

int main()
{
    int arr[] = {1, 4, 4, 1, 0, 1};
    func(arr, 6);
    for (auto x : arr)
    {
        cout << x << " ";
    }
    return 0;

    return 0;
}