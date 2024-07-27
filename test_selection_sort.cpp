#include <iostream>
#include <vector>
using namespace std;

void helper(vector<int> &arr, int n)
{

    for (int i = 0; i <= n - 2; i++)
    {
        int idx = i;

        for (int j = i + 1; j < n; j++)
        {

            if (arr[j] < arr[idx])
            {

                idx = j;
            }
        }
        if (idx != i)
        {

            swap(arr[idx], arr[i]);
        }
    }
}

int main()
{
    vector<int> arr = {12, 1, 14, 3, 4};
    cout << "Before Sorting" << endl;
    for (auto x : arr)
    {

        cout << x << " ";
    }
    cout << endl;
    helper(arr, arr.size());
    cout << "After Sorting" << endl;
    for (auto x : arr)
    {

        cout << x << " ";
    }
    return 0;
}
