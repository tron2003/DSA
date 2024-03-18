#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void func(int arr[], int n, int k)
{

    int mx = 0;
    for (int i = 0; i < n; i++)
    {

        mx = max(arr[i], mx);
    }
    mx++;
    vector<vector<int>> bkt(k);
    for (int i = 0; i < n; i++)
    {
        int bi = (arr[i] * k) / mx;
        bkt[bi].push_back(arr[i]);
        /* code */
    }
    for (int i = 0; i < k; i++)
    {
        sort(bkt[i].begin(), bkt[i].end());
    }
    int idx = 0;
    for (int i = 0; i < k; i++)
    {

        for (int j = 0; j < bkt[i].size(); j++)
        {
            arr[idx++] = bkt[i][j];
        }
    }
}

int main()
{

    int arr[] = {30,40,10,80,5,12,70};
    func(arr,7 ,4);
    for (auto x : arr)
    {
        cout << x << " ";
    }
    return 0;
}