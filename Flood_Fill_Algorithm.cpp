#include <iostream>
#include <bits/stdc++.h>
#include<vector>
using namespace std;

void dfs(int x, int y, vector<vector<int>> &arr, vector<vector<int>> &temp,
         int init, int newColor, vector<int> drow, vector<int> dcol)
{

    temp[x][y] = newColor;
    int m = arr.size();
    int n = arr[0].size();
    for (int i = 0; i < 4; i++)
    {

        int k1 = x + drow[i];
        int k2 = y + dcol[i];
        if (k1 >= 0 && k1 <= m - 1 && k2 >= 0 && k2 <= n - 1 &&
            arr[k1][k2] == init && temp[k1][k2] != newColor)
        {
            dfs(k1, k2, arr, temp, init, newColor, drow, dcol);
        }
    }
}
vector<vector<int>> floodFill(vector<vector<int>> &arr, int x, int y,
                              int newColor)
{
    // Write your code here.

    int m = arr.size();
    int n = arr[0].size();
    int init = arr[x][y];
    vector<vector<int>> temp = arr;
    vector<int> drow = {-1, 0, 1, 0};
    vector<int> dcol = {0, 1, 0, -1};

    dfs(x, y, arr, temp, init, newColor, drow, dcol);

    return temp;
}
int main()
{
    cout<<"Before ALgo"<<endl;
    vector<vector<int>> image = {{1, 1, 1},
                                 {1, 1, 0},
                                 {1, 0, 1}};

    for (int i = 0; i < image.size();i++){
        for (int j = 0; j < image[0].size();j++){

            cout << image[i][j] << " ";
        }
        cout << endl;
    }
        cout << endl;
        cout << "New graph" << endl;
        int sr = 1, sc = 1, newColor = 2;
    vector<vector<int>>temp=floodFill(image, sr, sc, newColor);
    for (int i = 0; i < image.size(); i++)
    {
        for (int j = 0; j < image[0].size(); j++)
        {

            cout << temp[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}