#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int pivot(int arr[], int l, int h)
{
    int p = arr[(l + h) / 2]; // Choosing pivot from the middle
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

int func(int arr[], int l, int h, int k)
{
    if (k < 1 || k > (h - l + 1))
        return -1; // Invalid k

    int p = pivot(arr, l, h);
    while (l < h)
    {
        if (p == k - 1)
        {
            return arr[p];
        }
        if (k - 1 < p)
        {
            h = p - 1;
        }
        else
        {
            l = p + 1;
        }
        p = pivot(arr, l, h);
    }

    return arr[l]; // If array size is 1
}

int main()
{
    int arr[5] = {10, 212, 5, 89, 100};
    cout << "2nd smallest element: " << func(arr, 0, 4, 2) << endl;
    cout << "Minimum k elements:" << endl;
    for (int k = 1; k <= 5; ++k) {
        cout << func(arr, 0, 4, k) << " ";
    }
    cout << endl;
    return 0;
}
