#include <iostream>
#include <bits/stdc++.h>

using namespace std;

bool check(vector<vector<int>> arr, int n, int x, int y)
{

    if (x >= 0 && x < n && y >= 0 && y < n && arr[x][y] == 1)
    {
        return true;
    }
    return false;
    ;
}
void helper(int x, int y, vector<vector<int>> &arr, int n, string str, vector<string> &res)
{

    if (x == n - 1 && y == n - 1  )
    {

        res.push_back(str);
        return;
    }
    arr[x][y] = 0;

    if (check(arr, n, x + 1, y))
    {
        str +='D';
        helper(x + 1, y, arr, n, str, res);
        str.pop_back();
    }
    if (check(arr, n, x - 1, y))
    {
        str += 'U';
        helper(x - 1, y, arr, n, str, res);
        str.pop_back();
    }
    if (check(arr, n, x , y+1))
    {
        str += 'R';
        helper(x, y+1, arr, n, str, res);
        str.pop_back();
    }
    if (check(arr, n, x , y-1))
    {
        str += 'L';
        helper(x , y-1, arr, n, str, res);
        str.pop_back();
    }
    arr[x][y] = 1;
}

void  func(vector<vector<int>> arr, int n)
{

    string str = "";
    vector<string> res;
    if (arr[0][0] == 0)
    {
        return;
    }
    helper(0, 0, arr, n, str, res);
    for(auto x:res){

        cout << x << " ";
    }

}

int main()
{

    vector<vector<int>> arr = {
     {1, 0, 0, 0},
     {1, 1, 0, 1},
     {1,1,0,0},
     {0,1,1,1}};
    func(arr, 4);

    return 0;
}