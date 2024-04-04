#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int func(vector<int> arr, int n)
{
    stack<int> st;
    int res = 0;
    for (int i = 0; i < n; i++)
    {
        while (!st.empty() && arr[st.top()] >= arr[i])
        {

            int tp = st.top();
            st.pop();
            int curr = arr[tp] * (st.empty() ? i : (i - st.top() - 1));
            res = max(res, curr);
        }
        st.push(i);
    }

    while (!st.empty())
    {
        int tp = st.top();
        st.pop();
        int curr = arr[tp] * (st.empty() ? n : (n - st.top() - 1));
        res = max(res, curr);
    }
    return res;
}

int func1(vector<vector<int>> arr)
{

    int row = arr.size();
    int col = arr[0].size();
    int res = func(arr[0], col);
    for (int i = 1; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (arr[i][j] == 1)
            {
                arr[i][j] += arr[i - 1][j];
            }
        }
        res = max(res, func(arr[i], col));
    }

    return res;
}

int main()
{
    vector<vector<int>> matrix = {
        {1, 0, 1, 0, 0},
        {1, 0, 1, 1, 1},
        {1, 1, 1, 1, 1},
        {1, 0, 0, 1, 0}
    };

    cout << "Maximum area of rectangle: " << func1(matrix) << endl;

    return 0;
}
