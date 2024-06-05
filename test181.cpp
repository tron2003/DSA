#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int x = 20;
void func(vector<int> &arr, int l, int h)
{
    if (l > h)
    {
        return;
    }
    for (int i = 0; i < h; i++)
    {
        if (arr[i] > arr[i + 1])
        {
            swap(arr[i], arr[i + 1]);
        }
    }
    func(arr, l, h - 1);
}

int main()
{
    vector<int> arr = {12, 34
    };
    func(arr, 0, 2);
    for(auto x:arr){
        cout << x << " ";
    }
    // cout << ans;
    return 0;
}