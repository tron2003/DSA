#include <iostream>
#include <bits/stdc++.h>
using namespace std;

vector<int> func(int arr[], int n)
{
    stack<int> st;
    st.push(n - 1);
    vector<int> res;
    res.push_back(-1);
    for (int i = n - 2; i >= 0; i--)
    {

        while (!st.empty() && arr[st.top()] < arr[i])
        {

            st.pop();
        }
        int span = st.empty() ? -1 : arr[st.top()];
        res.push_back(span);
        st.push(i);
    }
    reverse(res.begin(), res.end());
    return res;
}

int main()
{

    int arr[] = {10, 15, 20, 25};
    vector<int> str = func(arr, 4);
    for (auto x : str)
    {
        cout << x << ' ';
    }
    return 0;
}