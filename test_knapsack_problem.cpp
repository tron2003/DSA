#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#define mod 1000000007

int helper(vector<int> w, vector<int> p, int n, int cap)
{

    if (n == 0)
    {

        if (w[0] <= cap)
        {
            return p[0];
        }
        else
        {
            return 0;
        }
    }
    int inc = 0;
    if (w[n] <= cap)
    {
        inc = p[n] + helper(w, p, n - 1, cap - w[n]);
    }
    int exe = 0 + helper(w, p, n - 1, cap);

    int res = max(exe, inc);

    return res;
}

void func()
{
    vector<int> w = {1, 2, 3, 4};
    vector<int> p = {5, 4, 8, 6};
    int cap = 5;
    int n = w.size();
    // int i = n - 1;
    // vector<long long> dp(n + 1, 0);
    int res = helper(w, p, n - 1, cap);
    cout << res;
}

int main()
{
    func();
    return 0;
}