#include <iostream>
#include <vector>
using namespace std;

void maxheap(vector<int> &arr, int n, int i)
{
    int large = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    if (left < n && arr[left] > arr[large])
    {
        large = left;
    }
    if (right < n && arr[right] > arr[large])
    {
        large = right;
    }
    if (large != i)
    {
        swap(arr[i], arr[large]);
        maxheap(arr, n, large);
    }
}

void buildheap(vector<int> &arr, int n)
{
    for (int i = (n - 2) / 2; i >= 0; i--)
    {
        maxheap(arr, n, i);
    }
}

void heapsort(vector<int> &arr)
{
    int n = arr.size();
    buildheap(arr, n);
    for (int i = n - 1; i >= 1; i--)
    {
        swap(arr[0], arr[i]);
        maxheap(arr, i, 0);
    }
}

int main()
{
    vector<int> arr = {12, 11, 13, 5, 6, 7};
    heapsort(arr);
    cout << "Sorted array: ";
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}
