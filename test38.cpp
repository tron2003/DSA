#include <iostream>
#include <bits/stdc++.h>
using namespace std;
void maxheap(int arr[], int n, int i)
{
    int lar = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    if (right < n && arr[lar] < arr[right])
    {

        lar = right;
    }
    if (left < n && arr[lar] < arr[left])
    {

        lar = left;
    }
    if (lar != i)
    {
        swap(arr[lar], arr[i]);
        maxheap(arr, n, lar);
    }
}

void heapbuild(int arr[], int n)
{

    for (int i = (n - 2) / 2; i >= 0; i--)
    {

        maxheap(arr, n, i);
    }
}

void heapsort(int arr[], int n)
{

    heapbuild(arr, n);
    for (int i = n - 1; i >= 1; i--)
    {

        swap(arr[i], arr[0]);
        maxheap(arr, i, 0);
    }
}

int main()
{
    int arr[] = {23, 21, 30, 10, 7};
    heapsort(arr, 5);
    for (auto x : arr)
    {
        cout << x << " ";
    }

    return 0;
}