#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool ischeck(vector<int> &arr, int n, int m, int mid)
{
    int count = 1;
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        if (sum + arr[i] <= mid)
        {
            sum += arr[i];
        }
        else
        {
            count++;
            if (count > m || arr[i] > mid)
            {
                return false;
            }
            sum = arr[i];
        }
    }
    return true;
}

int findPages(vector<int> &arr, int n, int m)
{
    int l = 0;
    int h = 0;
    if (m > n)
    {
        return -1;
    }
    for (int i = 0; i < n; i++)
    {
        h += arr[i];
        l = max(l, arr[i]);
    }
    int res = -1;
    while (l <= h)
    {
        int mid = l + (h - l) / 2;
        if (ischeck(arr, n, m, mid))
        {
            res = mid;
            h = mid - 1;
        }
        else
        {
            l = mid + 1;
        }
    }
    return res;
}

int main()
{
    vector<int> arr1 = {12, 34, 67, 90};
    int n1 = arr1.size();
    int m1 = 2;
    cout << "Test Case 1: " << findPages(arr1, n1, m1) << endl; // Expected output: 113

    vector<int> arr2 = {10, 20, 30, 40};
    int n2 = arr2.size();
    int m2 = 2;
    cout << "Test Case 2: " << findPages(arr2, n2, m2) << endl; // Expected output: 60

    vector<int> arr3 = {10, 20, 30, 40, 50, 60, 70, 80};
    int n3 = arr3.size();
    int m3 = 4;
    cout << "Test Case 3: " << findPages(arr3, n3, m3) << endl; // Expected output: 110

    vector<int> arr4 = {5, 17, 100, 11};
    int n4 = arr4.size();
    int m4 = 2;
    cout << "Test Case 4: " << findPages(arr4, n4, m4) << endl; // Expected output: 117

    vector<int> arr5 = {10, 20, 30};
    int n5 = arr5.size();
    int m5 = 4;
    cout << "Test Case 5: " << findPages(arr5, n5, m5) << endl; // Expected output: -1

    return 0;
}
