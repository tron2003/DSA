#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void median(vector<int> arr, int n)
{
    priority_queue<int> s;                            // max heap for elements less than current median
    priority_queue<int, vector<int>, greater<int>> q; // min heap for elements greater than current median
    s.push(arr[0]);
    cout << arr[0] << " ";

    for (int i = 1; i < n; i++)
    {
        int x = arr[i];

        if (s.size() > q.size())
        {
            if (x < s.top())
            {
                q.push(s.top());
                s.pop();                    
                s.push(x);
            }
            else
            {
                q.push(x);
            }
            cout << s.top() << " ";
        }
        else if (s.size() == q.size())
        {
            if (x < s.top())
            {
                s.push(x);
                cout << s.top() << " ";
            }
            else
            {
                q.push(x);
                cout << q.top() << " ";
            }
        }
        else
        {
            if (x > q.top())
            {
                s.push(q.top());
                q.pop();
                q.push(x);
            }
            else
            {
                s.push(x);
            }
            cout << s.top() << " ";
        }
    }
}

int main()
{
    vector<int> arr = {25, 7, 10, 15, 20};
    median(arr, arr.size());
    return 0;
}
