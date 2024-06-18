#include <iostream>
#include <bits/stdc++.h>

using namespace std;

vector<int> prevsmaller(vector<int> mat)
{
    stack<int> st;
    st.push(-1);
    vector<int> res(mat.size()+1);
    // int res = INT_MIN;
    int n = mat.size();
    for (int i = 0; i < n; i++)
    {

        while (!st.empty() && st.top() != -1 && mat[st.top()] >= mat[i])
        {
            st.pop();
        }
        res[i] = st.top();

        st.push(i);
    }
    return res;
    // return res;
}
vector<int> nextsmaller(vector<int> mat)
{
    stack<int> st;
    st.push(-1);
    vector<int> res(mat.size(),0);
    int n = mat.size();
    for (int i = n - 1; i >= 0; i--)
    {

        while (!st.empty() && st.top() != -1 && mat[st.top()] >= mat[i])
        {
            st.pop();
        }
        res[i] = st.top();

        st.push(i);
    }

    return res;
    // return res;
}
int helper(vector<int>arr){

    vector<int> next = nextsmaller(arr);
    vector<int> prev = prevsmaller(arr);
    int res = INT_MIN;
    for (int i = 0; i < arr.size();i++){

        if(next[i]==-1){
            next[i] = arr.size();
        }
        int l = arr[i];
        int b = next[i] - prev[i] - 1;
        int temp = l * b;
        res = max(res, temp);
    }
    return res;
}


void func()
{

    vector<vector<int>> mat = {{0, 1}, {1, 0}};
    int res = INT_MIN;
    vector<int> hist(mat[0].size(), 0);
    for (int i = 0; i < mat.size(); i++)
    {

        for (int j = 0; j < mat[0].size(); j++)
        {

            if (mat[i][j] == 1)
            {

                hist[j]++;
            }
            else
            {
                hist[j] = 0;
            }
        }
        res = max(res, helper(hist));
    }

    // vector<vector<int>> dp(s1.size() + 1, vector<int>(s2.size() + 1, -1));
    // int res = helper_memo(s1, 0, s2, 0, dp);
    // int res = helper_tab(s1, s2);
    // int res = helper_sc(s1, s2);

    cout << res;
}

int main()
{
    func();
    return 0;
}
