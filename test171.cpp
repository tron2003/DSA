#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int func(vector<int> arr, int n)
{

    vector<int> dp(n + 1, 0);
    int prev_prev = arr[0];
    int prev = max(arr[0], arr[1]);
    int res = prev;
    for (int i = 3; i <= n; i++)
    {

        res = max(prev, prev_prev + arr[i - 1]);
        prev_prev = prev;
        prev = res;
    }
    return res;
}

int main()
{
    cout << func({1, 10, 2}, 3);
    return 0;
}