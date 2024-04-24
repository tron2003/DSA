#include <iostream>
#include <vector>
#include <stack>
using namespace std;

void printCeilingOnLeft(int arr[], int n)
{
    stack<int> s;
    vector<int> result;

    for (int i = 0; i < n; i++)
    {
        while (!s.empty() && s.top() <= arr[i])
        {
            s.pop();
        }
        if (s.empty())
        {
            result.push_back(-1);
        }
        else
        {
            result.push_back(s.top());
        }
        s.push(arr[i]);
    }

    cout << "Ceiling on the left side for each element: ";
    for (int num : result)
    {
        cout << num << " ";
    }
    cout << endl;
}

int main()
{
    int arr[] = {2, 5, 3, 7, 8, 6};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Original array: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    printCeilingOnLeft(arr, n);

    return 0;
}
