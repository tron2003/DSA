#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int helper_space_12(vector<int> w, vector<int> p, vector<vector<int>> &dp, int n, int cap)
{

    vector<int> temp1(cap + 1, 0);
    vector<int> temp2(cap + 1, 0);

    for (int i = w[0]; i <= cap; i++)
    {

        if (w[0] <= cap)
        {
            temp1[i] = p[0];
        }
        else
        {
            temp1[i] = 0;
        }
    }
    for (int i = 1; i < n; i++)
    {

        for (int j = cap; j >= 0; j--)
        {

            int inc = 0;
            if (w[i] <= j)
            {

                inc = p[i] + temp1[j - w[i]];
            }
            int exe = 0 + temp1[j];
            temp2[j] = max(inc, exe);
        }
        temp1 = temp2;

    }
    return temp1[cap];
}
int helper_space_1(vector<int> w, vector<int> p, vector<vector<int>> &dp, int n, int cap)
{

    vector<int> temp1(cap + 1, 0);


    for (int i = w[0]; i <= cap; i++)
    {

        if (w[0] <= cap)
        {
            temp1[i] = p[0];
        }
        else
        {
            temp1[i] = 0;
        }
    }
    for (int i = 1; i < n; i++)
    {

        for (int j = 0; j <= cap; j++)
        {

            int inc = 0;
            if (w[i] <= j)
            {

                inc = p[i] + temp1[j - w[i]];
            }
            int exe = 0 + temp1[j];
            temp1[j] = max(inc, exe);
        }
     

    }
    return temp1[cap];
}

int helper(vector<int> w, vector<int> p, vector<vector<int>> &dp, int n, int cap)
{

    for (int i = w[0]; i <= cap; i++)
    {

        if (w[0] <= cap)
        {
            dp[0][i] = p[0];
        }
        else
        {
            dp[0][i] = 0;
        }
    }
    for (int i = 1; i < n; i++)
    {

        for (int j = 0; j <= cap; j++)
        {

            int inc = 0;
            if (w[i] <= j)
            {

                inc = p[i] + dp[i - 1][j - w[i]];
            }
            int exe = 0 + dp[i - 1][j];
            dp[i][j] = max(inc, exe);
        }
    }
    return dp[n - 1][cap];
}

void func()
{
    vector<int> w = {1, 2, 3, 4, 5};
    vector<int> p = {5, 4, 8, 6};
    int cap = 5;
    int n = w.size();
    // int i = n - 1;
    vector<vector<int>> dp(n, vector<int>(cap + 1, INT_MIN));
    // int res = helper(w, p, dp, n, cap);
    // int res = helper_space(w, p, dp, n, cap);
    int res = helper_space_1(w, p, dp, n, cap);
    cout << res;
}

int main()
{
    func();
    return 0;
}