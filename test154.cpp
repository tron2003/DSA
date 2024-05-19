#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// vector<int>steps
bool issafe(vector<vector<int>> arr, int i, int j)
{

    if (j < arr[0].size() && j >= 0 && i < arr.size() && i >= 0 &&arr[i][j]==1)
    {
        return true;
    }
}
bool funcres(vector<vector<int>> arr, int i, int j)
{

    if (j == arr[0].size() - 1 && i == arr.size() - 1 && arr[i][j] == 1)
    {
        return true;
    }
    if (issafe(arr, i, j))
    {
        arr[i][j] = 0;

        if (funcres(arr, i + 1, j))
        {
            return true;
            ;
        }
        if (funcres(arr, i, j + 1))
        {
            return true;
        }
        arr[i][j] = 1;
    }

    return false;
}

bool func12(vector<vector<int>> arr, int n)
{
    int i = 0;
    int j = 0;
    return funcres(arr, 0, 0);
}

int main()
{
    vector<vector<int>> arr = {{1, 0, 0, 0}, {1, 1, 0, 1}, {0, 1, 0, 0}, {1, 1, 1, 1}};
    cout << func12(arr, arr.size());
    return 0;
}