#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void merge(vector<int> &arr, int low, int mid, int high)
{
    int n = arr.size();
    int m1 = mid-low+1;
    int m2 = high - mid;
    vector<int> arr1(m1, 0);
    vector<int> arr2(m2, 0);
    for (int i = 0; i < m1; i++)
    {

        arr1[i] = arr[i + low];
    }
    for (int i = 0; i < m2; i++)
    {

        arr2[i] = arr[mid + i + 1];
    }
    int i = 0;
    int j = 0;
    int k =low;
    while (i < m1 && j < m2)
    {

        if (arr1[i] <= arr2[j])
        {

            arr[k++] = arr1[i++];
        }
        else
        {

            arr[k++] = arr2[j++];
        }
    }
    while (i < m1)
    {
        arr[k++] = arr1[i++];
    }
    while (j < m2)
    {

        arr[k++] = arr2[j++];
    }
}

void mergesort(vector<int> &arr, int low, int high)
{

    if (low < high)
    {

        int mid = low + (high - low) / 2;
        mergesort(arr, low, mid);
        mergesort(arr, mid + 1, high);
        merge(arr, low, mid, high);
    }
}

int main()
{

    vector<int> arr = {5, 3, 4, 2, 6, 7};
    int n = arr.size();
    for (auto x : arr)
    {

        cout << x << "  ";
    }
    cout << endl;
    mergesort(arr, 0, n - 1);
    for (auto x : arr)
    {

        cout << x << "  ";
    }

    return 0;
}
