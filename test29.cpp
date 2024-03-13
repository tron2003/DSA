#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int pivot(int arr[], int l, int h)
{
    int mid = (l + h) / 2;
    int p = arr[mid]; // Choosing pivot from the middle
    int i = l - 1;
    int j = h + 1;
    while (true)
    {
        do
        {
            i++;
        } while (arr[i] < p);
        do
        {
            j--;
        } while (arr[j] > p);

        if (i >= j)
        {
            return j;
        }
        swap(arr[i], arr[j]);
    }
}

void sort1(int arr[], int l, int h)
{
    if (l < h)
    {
        int p = pivot(arr, l, h);
        sort1(arr, l, p);
        sort1(arr, p + 1, h);
    }
}

int main()
{
    int arr[5] = {10, 212, 5, 89, 100};
    sort1(arr, 0, 4);
    for (auto x : arr)
    {
        cout << x << " ";
    }

    return 0;
}
