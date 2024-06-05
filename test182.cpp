#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void merge(vector<int> &arr, int l, int h, int mid)
{
    int m = mid + 1 - l;
    int n = h - mid;
    int left[m];
    int right[n];
    for (int i = 0; i < m; i++)
    {

        left[i] = arr[i+l];
    }
    for (int i = 0; i < n; i++)
    {
        right[i] = arr[mid + 1 + i];
    }
    int i = 0;
    int j = 0;
    int k = l;
    while (i < m && j < n)
    {

        if (left[i] <=right[j])
        {
            arr[k++] = left[i++];
            
        }
        else{

            arr[k++] =right[j++];
        }
    }
    while(i<m){
        arr[k++] = left[i++];
    }
    while(j<n){
        arr[k++] = right[j++];
    }
   
}

void mergesort(vector<int> &  arr, int l, int h)
{

    if (l < h)
    {
        int mid = l + (h - l) / 2;
        mergesort(arr, l, mid);
        mergesort(arr, mid + 1, h);
        merge(arr, l, h,mid);
    }
}

int main()
{
    vector<int> arr = {21, 10, 1, 12, 45};

    mergesort(arr, 0, 4);
    for (auto x : arr)
    {

        cout << x << " ";
    }
    return 0;
}