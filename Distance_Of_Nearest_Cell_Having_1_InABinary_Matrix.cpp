#include <iostream>
#include <bits/stdc++.h>
#include<vector>
using namespace std;

vector<vector<int>>nearest(vector<vector<int>>&arr,int n,int m)
{

    vector<vector<int>> dist(n, vector<int>(m, 0));
    vector<vector<int>> vis(n, vector<int>(m, 0));
    queue<pair<pair<int, int>, int>> que;
    for (int i = 0; i < n; i++)
    {

        for (int j = 0; j < m; j++)
        {

            if (arr[i][j] == 1)
            {

                que.push({{i, j}, 0});
                vis[i][j] = 1;
            }
        }
    }
    while (!que.empty())
    {

        auto i = que.front().first.first;
        auto j = que.front().first.second;
        auto steps = que.front().second;
        dist[i][j] = steps;
        que.pop();
        vector<int> row = {0, 1, -1, 0};
        vector<int> col = {1, 0, 0, -1};
        for (int k = 0; k < 4; k++)
        {
            int newi = i + row[k];
            int newj = j + col[k];
            if (newi >= 0 && newi < n && newj >= 0 && newj < m &&
                vis[newi][newj] == 0)
            {

                vis[newi][newj] = 1;
                que.push({{newi, newj}, steps + 1});
            }
        }
    }

    return dist;
}

int main()
{
    cout << "before "<<endl;
    vector<vector<int>> arr = {
        {0, 0, 0},
        {0, 1, 0},
        {0, 0, 0}};
    int n = 3, m = 3;
    for (int i = 0; i < n; i++)
    {

        for (int j = 0; j < m; j++)
        {

            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    cout << "after "<<endl;
    vector<vector<int>>arr1=nearest(arr, m, m);
    for (int i = 0; i < n; i++)
    {

        for (int j = 0; j < m; j++)
        {

            cout << arr1[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}