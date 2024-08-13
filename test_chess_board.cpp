#include <iostream>
#include <vector>
using namespace std;

bool check(vector<vector<char>> arr, int row, int col, char c)
{

    for (int i = 0; i < 9; i++)
    {

        if (arr[i][col] == c)
        {
            return false;
        }
        if (arr[row][i] == c)
        {
            return false;
        }
        if (arr[3 * (row / 3) + (i / 3)][3 * (col / 3) + (i % 3)] == c)
        {
            return false;
        }
    }

    return true;
}

bool solve(vector<vector<char>> &arr)
{

    for (int i = 0; i < arr.size(); i++)
    {

        for (int j = 0; j < arr[0].size(); j++)
        {
            if (arr[i][j] == '.')
            {
                for (char c = '1'; c <= '9'; c++)
                {

                    if (check(arr, i, j, c))
                    {
                        arr[i][j] = c;
                        if (solve(arr))
                        {
                            return true;
                        }
                        arr[i][j] = '.';
                    }
                }
                return false;
            }
        }
    }
    return true;
}

void helper(vector<vector<char>> &arr)
{
    solve(arr) ? cout << "Its is possible " : cout << "Its not possible";
}

int main()
{
    int n = 9;

    vector<vector<char>> arr(9, vector<char>(9, '.'));
    helper(arr);
    return 0;
}
