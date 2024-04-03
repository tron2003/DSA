#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int func(int arr[], int n)
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

int main()
{

    int arr[] = {2, 5, 1};
    int str = func(arr, 3 );
    cout << str << ' ';
    return 0;
}