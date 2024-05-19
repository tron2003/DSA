#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

bool issafe(vector<vector<int>> &arr, int r, int c, int x)
{
    int n = arr.size();
    for (int k = 0; k < n; k++)
    {
        if (arr[k][c] == x || arr[r][k] == x)
        {
            return false;
        }
    }
    int s = sqrt(n);
    int rs = r - (r % s);
    int cs = c - (c % s);
    for (int i = 0; i < s; i++)
    {
        for (int j = 0; j < s; j++)
        {
            if (arr[i + rs][j + cs] == x)
            {
                return false;
            }
        }
    }
    return true;
}

bool findEmptyCell(vector<vector<int>> &arr, int &row, int &col)
{
    int n = arr.size();
    for (row = 0; row < n; row++)
    {
        for (col = 0; col < n; col++)
        {
            if (arr[row][col] == 0)
            {
                return true;
            }
        }
    }
    return false;
}

bool func(vector<vector<int>> &arr)
{
    int row, col;
    if (!findEmptyCell(arr, row, col))
    {
        return true;
    }
    for (int x = 1; x <= arr.size(); x++)
    {
        if (issafe(arr, row, col, x))
        {
            arr[row][col] = x;
            if (func(arr))
            {
                return true;
            }
            arr[row][col] = 0;
        }
    }
    return false;
}

void printGrid(const vector<vector<int>> &arr)
{
    for (const auto &row : arr)
    {
        for (int num : row)
        {
            cout << num << " ";
        }
        cout << endl;
    }
}

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> arr(n, vector<int>(n, 0));
    if (func(arr))
    {
        printGrid(arr);
    }
    else
    {
        cout << "No solution exists!" << endl;
    }
    return 0;
}
