#include <iostream>
#include <algorithm>
using namespace std;

template<size_t N>
void func(int (&arr)[N]) // Accepting array by reference using template
{
    for (int i = 0; i < N - 1; i++)
    {
        int mid = i;
        for (int j = i + 1; j < N; j++)
        {
            if (arr[j] < arr[mid])
            {
                mid = j;
            }
        }
        swap(arr[mid], arr[i]);
    }
}

int main()
{
    int arr1[] = {10, 91, 212, 21, 2432};
    func(arr1);
    for (auto x : arr1)
    {
        cout << x << " ";
    }
    return 0;
}
