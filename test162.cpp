#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int func(vector<int> arr)
{
    int n = arr.size();
    vector<int> m(arr.size(), 1);
    for (int i = 0; i < n; i++)
    {
        
        for (int j = 0; j < i; j++)
        {
            if (arr[j] < arr[i] &&m[i] <m[j]+1)
            {
                m[i] = m[j] + 1;
            }
        }
    }
    int res = m[0];
    for (int i = 1; i < n; i++)
    {

        res = max(res, m[i]);
    }
    return res;
}

int main()
{
    vector<int> arr = {3, 4, 2, 8, 10};
    cout << func(arr);
    return 0;
}