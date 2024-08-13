#include <iostream>
#include <vector>
using namespace std;

bool check(vector<string> &arr, int row, int col)
{
    int n = arr.size();

    // Check upper left diagonal
    int dirow = row - 1;
    int dicol = col - 1;
    while (dirow >= 0 && dicol >= 0)
    {
        if (arr[dirow][dicol] == 'Q')
        {
            return false;
        }
        dirow--;
        dicol--;
    }

    // Check upper right diagonal
    int dirowright = row - 1;
    int dicolright = col + 1;
    while (dirowright >= 0 && dicolright < n)
    {
        if (arr[dirowright][dicolright] == 'Q')
        {
            return false;
        }
        dirowright--;
        dicolright++;
    }

    // Check upper column
    int toprow = row - 1;
    while (toprow >= 0)
    {
        if (arr[toprow][col] == 'Q')
        {
            return false;
        }
        toprow--;
    }

    return true;
}

void helper(vector<vector<string>> &arr, vector<string> &temp, int row)
{
    int n = temp.size();
    if (row == n)
    {
        arr.push_back(temp);
        return;
    }

    for (int i = 0; i < n; i++)
    {
        if (check(temp, row, i))
        {
            temp[row][i] = 'Q';
            helper(arr, temp, row + 1);
            temp[row][i] = '.'; // Backtrack
        }
    }
}

int main()
{
    int n = 4;

    vector<vector<string>> arr;
    vector<string> temp(n, string(n, '.')); // Initialize n strings of n characters each, all set to '.'

    helper(arr, temp, 0);

    // Output the solutions
    for (const auto &solution : arr)
    {
        for (const auto &row : solution)
        {
            cout << row << endl;
        }
        cout << endl; // Separate solutions by a blank line
    }

    return 0;
}
