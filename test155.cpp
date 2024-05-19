#include <iostream>
#include <bits/stdc++.h>
using namespace std;

bool issafe(vector<vector<int>> arr, int r, int c)
{

    for (int i = 0; i < c; i++)
    {
        if (arr[r][i])
        {
            return false;
        }
    }
    for (int i = r, j = c; j >= 0 &&i >= 0; j--, i--)
    {

        if (arr[i][j])
        {
            return false;
        }
    }
    for (int i = r, j = c; i < arr.size() &&j >= 0; i++, j--)
    {

        if (arr[i][j])
        {
            return false;
        }
    }
    return true;
}

bool funcres(vector<vector<int>> arr, int col)
{

    if (col >= arr.size())
    {
        return true;
    }
    for (int i = 0; i < arr.size(); i++)
    {

        if (issafe(arr, i, col))
        {
            arr[i][col] = 1;

            if (funcres(arr, col + 1))
            {

                return true;
            }

            arr[i][col] = 0;
        }
    }
    return false;
}

bool func(vector<vector<int>> arr)
{

    return funcres(arr, 0);
}

int main()
{
    int n = 0;
    cin >> n;
    vector<vector<int>> arr(n, vector<int>(n, 0));
    cout << func(arr);
    return 0;
}