#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void func(int arr[], int n)
{
    int low = 0;
    int high = n - 1;
    int mid = low;
    // int j =n;
    while (mid <= high)
    {

        if (arr[mid] == 0)
        {
            swap(arr[low], arr[mid]);
            low++;

            mid++;

            // }
        }
        else if (arr[mid] == 1)
        {
            mid++;
        }
        else
        {
            swap(arr[mid], arr[high]);
            high--;
        }
    }
}

int main()
{
    int arr[] = {0,1,2,2,1,0,0,1,1};
    func(arr, sizeof(arr)/sizeof(arr[0]));
    for (auto x : arr)
    {
        cout << x << " ";
    }

    return 0;
}