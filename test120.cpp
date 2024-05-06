
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void sort(vector<int> &arr, int k)
{                                                       // Corrected: Pass arr by reference
    priority_queue<int, vector<int>, greater<int>> que; // Corrected: Added vector<int> template argument

    for (int i = 0; i <=k; i++)
    {
        que.push(arr[i]);
    }
    int idx = 0;
    for (int i = k+1; i <arr.size(); i++)
    {
        arr[idx++] = que.top();
        que.pop();
       
        que.push(arr[i]);
    }
    while (!que.empty())
    { // Corrected: Changed que.empty()==false to !que.empty()
        arr[idx++] = que.top();
        que.pop();
    }
}

int main()
{
    // Test Case 1
    vector<int> arr1 = {3, 2, 1, 5, 4};
    int k1 = 1;
    sort(arr1, k1);
    cout << "Test Case 1: ";
    for (int num : arr1)
    {
        cout << num << " ";
    }
    cout << endl;

    // Test Case 2
    vector<int> arr2 = {5, 4, 3, 2, 1};
    int k2 = 2;
    sort(arr2, k2);
    cout << "Test Case 2: ";
    for (int num : arr2)
    {
        cout << num << " ";
    }
    cout << endl;

    // Test Case 3
    vector<int> arr3 = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    int k3 = 3;
    sort(arr3, k3);
    cout << "Test Case 3: ";
    for (int num : arr3)
    {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
