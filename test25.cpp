#include <iostream>
using namespace std;

int func(int arr[], int n)
{
    int slow = arr[0]+1;
    int fast = arr[0]+1;
    do
    {
        slow = arr[slow]+1;
        fast = arr[arr[fast]+1]+1;
    } while (slow != fast);

    slow = arr[0]+1;
    while (slow != fast)
    {
        slow = arr[slow]+1;
        fast = arr[fast]+1;
    }

    return slow;
}

int main()
{
    int arr[] = {0, 1, 2, 3, 4, 2};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << func(arr, n);

    return 0;
}
