#include <bits/stdc++.h>

using namespace std;

bool isAllowed(int i, int j, vector<vector<int>> &arr, int n, vector<vector<bool>> &visited)
{

    if ((i >= 0 && i < n) && (j >= 0 && j < n) && arr[i][j] == 1 && visited[i][j] == 0)
    {

        return true;
    }

    return false;
}

void solve(int i, int j, vector<vector<int>> &arr, int n, vector<string> &ans, string path, vector<vector<bool>> &visited)
{

    if (i == n - 1 && j == n - 1)
    {

        ans.push_back(path);

        return;
    }

    // going down

    if (isAllowed(i + 1, j, arr, n, visited))
    {

        visited[i][j] = 1;

        solve(i + 1, j, arr, n, ans, path + 'D', visited);

        visited[i][j] = 0;
    }

    // going left

    if (isAllowed(i, j - 1, arr, n, visited))
    {

        visited[i][j] = 1;

        solve(i, j - 1, arr, n, ans, path + 'L', visited);

        visited[i][j] = 0;
    }

    // going right

    if (isAllowed(i, j + 1, arr, n, visited))
    {

        visited[i][j] = 1;

        solve(i, j + 1, arr, n, ans, path + 'R', visited);

        visited[i][j] = 0;
    }

    // going up

    if (isAllowed(i - 1, j, arr, n, visited))
    {

        visited[i][j] = 1;

        solve(i - 1, j, arr, n, ans, path + 'U', visited);

        visited[i][j] = 0;
    }
}

vector<string> searchMaze(vector<vector<int>> &arr, int n)
{

    vector<string> ans;

    string path = "";

    vector<vector<bool>> visited(n, vector<bool>(n, false));

    if (arr[0][0] == 0)
    {

        return ans;
    }

    solve(0, 0, arr, n, ans, path, visited);

    return ans;
}