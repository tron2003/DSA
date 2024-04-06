#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void func(int arr[], int k)
{

    deque<int> que;

    for (int i = 0; i < k; i++)
    {
        while (que.empty() == false && arr[i] >= arr[que.back()])
        {

            que.pop_back();
        }
        que.push_back(i);
    }
    for (int i = k; i < 7; i++)
    {

        cout << arr[que.front()] << " ";
        while (!que.empty() && que.front() <= i - k)
        {
            que.pop_front();
        }
        while(!que.empty() &&arr[i]>=arr[que.back()]){
            que.pop_back();
        }
        if(i<7)
        {
            que.push_back    (i);
        }
    }
}

int main()
{
    int arr[7] = {10, 8, 5, 12, 15, 7, 6};
    func(arr, 3);

    return 0;
}