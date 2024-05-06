#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void sort(vector<int> arr, int k)
{

    priority_queue<int> que;

    for (int i = 0; i < k && i < arr.size(); i++)
    {

        que.push(arr[i]);
    }
    for (int i = k; i < arr.size(); i++)
    {

        if (arr[i] > que.top())
        {
            que.pop();
            que.push(arr[i]);
        }
    }
    while (que.empty() == false)
    {

        cout << que.top() << " ";
        que.pop();
    }
}

int main()
{
    vector<int> arr = {8, 12, 89, 21, 43};
    sort(arr, 2);
    return 0;
}