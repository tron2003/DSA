#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void sort(vector<int> arr, int x, int d)
{

    priority_queue<int,vector<int>,greater<int>> que;
    for (int i = 0; i < d; i++)
    {

        que.push(arr[i]);
    }
    for (int i = d; i < arr.size(); i++)
    {

        if (abs(arr[i] - x) < abs(que.top() - x) && que.size() <= d)
        {

            que.pop();
            que.push(arr[i]);
        }
    }
    while(!que.empty()){
        cout << que.top() << " ";
        que.pop();
    }
}

int main()
{
    vector<int> arr = {10, 15, 7, 3, 4};
    sort(arr, 8, 2);
    return 0;
}