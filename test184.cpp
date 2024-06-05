#include <iostream>
#include <vector>
using namespace std;

void helper(vector<int> arr, int idx, vector<int> temp, vector<vector<int>> &res)
{
    if (idx >= arr.size())
    {
        res.push_back(temp);
        return;
    }

    helper(arr, idx + 1, temp, res);

    temp.push_back(arr[idx]);
    helper(arr, idx + 1, temp, res);

}

vector<vector<int>> func(vector<int> &arr)
{
    vector<vector<int>> ans;
    vector<int> temp;
    int idx = 0;
    helper(arr, idx, temp, ans);
    return ans;
}

int main()
{
    vector<int> arr = {1, 2, 3};

    vector<vector<int>> res = func(arr);
    for (auto &x : res)
    {
        for (auto &y : x)
        {
            cout << y << " ";
        }
        cout << endl;
    }
    return 0;
}
