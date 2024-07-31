#include <bits/stdc++.h>
#include <iostream>
#include <bits/stdc++.h>
#include <vector>
using namespace std;

int minTimeToRot(vector<vector<int>> &arr, int m, int n)
{

    queue<pair<int, pair<int, int>>> que;
    vector<vector<int>> res(m + 1, vector<int>(n + 1, 0));
    int tm = 0;
    int cntfresh = 0;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {

            if (arr[i][j] == 2)
            {

                res[i][j] = 2;
                que.push({0, {i, j}});
            }
            if (arr[i][j] == 1)
            {
                cntfresh++;
            }
        }
    }
    int cnt = 0;
    int arr1[] = {1, -1, 0, 0};
    int arr2[] = {0, 0, 1, -1};
    while (!que.empty())
    {

        int newtime = que.front().first;
        int x = que.front().second.first;
        int y = que.front().second.second;
        que.pop();
        tm = max(tm, newtime);
        for (int i = 0; i < 4; i++)
        {
            int newx = x + arr1[i];
            int newy = y + arr2[i];
            if (newx >= 0 && newx <= m - 1 && newy >= 0 && newy <= n - 1 &&
                res[newx][newy] == 0 && arr[newx][newy] == 1)
            {

                que.push({newtime + 1, {newx, newy}});
                res[newx][newy] = 2;
                cnt++;
            }
        }
    }
    if (cnt != cntfresh)
    {
        return -1;
    }

    return tm;
}
int main(){


vector<vector<int>> arr = {{2, 1, 1},
                           {1, 1, 0},
                           {0, 1, 1}};
int m = 3, n = 3;

cout << minTimeToRot(arr, m, n)<<endl;

return 0;
}

