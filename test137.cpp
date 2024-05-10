#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int func(vector<vector<int>> arr, int v)
{
    vector<int> key(v , INT_MAX);
    key[0] = 0;
    vector<bool> mset(v , false);
    int res = 0;
    for (int count = 0; count < v; count++)
    {
        int u = -1;
        for (int i = 0; i < v; i++)
        {
            if (!mset[i] && (u == -1 || key[i] < key[u]))
            {
                u = i;
            }
        }
        mset[u] = true;
        res = res + key[u];
        for (int i = 0; i < v; i++)
        {
            if (arr[u][i] != 0 &&  arr[u][i] <key[i])
            {
                key[i] = arr[u][i];
            }
        }
    }
    for(auto x:key){
        cout << x << " ";
    }
    cout << endl;
    return res;
}

int main()
{

    vector<vector<int>> res = {{0, 5, 8, 0}, {5, 0, 10, 0}, {8, 10, 0, 20}, {0, 15, 20, 0}};
    cout << func(res, 4);
    return 0;
}