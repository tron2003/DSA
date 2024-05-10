#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int func(vector<vector<int>> arr, int v)
{
    vector<int> key(v, INT_MAX);
    vector<bool> vis(v, false);
    int res = 0;
    key[0] = 0;
    for (int i = 0; i < v - 1; i++)
    {
        int curr = -1;
        for (int j = 0; j < v; j++)
        {
            if (!vis[j] && (curr == -1 || key[curr] > key[j]))
            {
                curr = j;
  vis[curr] = true;
            }
        }

        for (int j = 0; j < v; j++)
        {
            if (!vis[j] && arr[curr][j] != 0)
            {
                key[j] = min(key[j], key[curr] + arr[curr][j]);
            }
        }
    }
    for (auto x : key)
    {
        cout << x << " ";
        res += x;
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