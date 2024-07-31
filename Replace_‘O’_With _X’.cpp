#include <iostream>
using namespace std;
#include <bits/stdc++.h>
void dfs(char **arr, vector<vector<int>> &vis, int n, int m, int i, int j)
{

    vector<int> row = {0, 0, 1, -1};
    vector<int> col = {1, -1, 0, 0};
    vis[i][j] = 1;
    for (int k = 0; k < 4; k++)
    {
        int newi = row[k] + i;
        int newj = col[k] + j;
        if (newi >= 0 && newi <= n - 2 && newj >= 0 && newj <= m - 2 &&
            arr[newi][newj] == 'O' && vis[newi][newj] == 0)
        {
            dfs(arr, vis, n, m, newi, newj);
        }
    }
}

void replaceOWithX(char **arr, int n, int m)
{
    vector<vector<int>> vis(n, vector<int>(m, 0));

    for (int i = 0; i < m; i++)
    {
        if (arr[0][i] == 'O' && !vis[0][i])
        {

            dfs(arr, vis, n, m, 0, i);
        }
    }
    for (int i = 0; i < n; i++)
    {

        if (arr[i][0] == 'O' && !vis[i][0])
        {

            dfs(arr, vis, n, m, i, 0);
        }
    }
    for (int i = 0; i < n; i++)
    {

        if (arr[i][m - 1] == 'O' && !vis[i][m - 1])
        {

            dfs(arr, vis, n, m, i, m - 1);
        }
    }
    for (int i = 0; i < m; i++)
    {

        if (arr[n - 1][i] == 'O' && !vis[n - 1][i])
        {

            dfs(arr, vis, n, m, n - 1, i);
        }
    }

    for (int i = 0; i < n; i++)
    {

        for (int j = 0; j < m; j++)
        {

            if (vis[i][j] == 0 && arr[i][j] == 'O')
            {
                arr[i][j] = 'X';
            }
        }
    }
}