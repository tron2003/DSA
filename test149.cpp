#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int func(vector<pair<int, int>> arr, int n)
{
    int res = 1;
    sort(arr.begin(), arr.end());

    int prev = 0;

    for (int i = 1; i < n; i++)
    {
        if (arr[i].first >=arr[prev].second){
            res++;
            prev = i;
        }
    }

    return res;
}

int main()
{
    vector<pair<int, int>> arr = {{12, 25}, {10, 20}, {20,30}};
    cout << func(arr,3);

    return 0;
}