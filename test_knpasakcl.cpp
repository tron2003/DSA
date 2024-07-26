#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int helper(vector<int> w, vector<int> p, int n, int cap)
{
    vector<vector<int>> dp(n, vector<int>(cap + 1, 0));

    for (int i = w[0]; i <= cap; i++)
    {
        dp[0][i] = p[0];
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
            int exe = dp[i - 1][j];
            dp[i][j] = max(inc, exe);
        }
    }
    return dp[n - 1][cap];
}

void func()
{
    vector<int> w = {1, 2, 3, 4, 5};
    vector<int> p = {5, 4, 8, 6, 7};
    int cap = 5;
    int n = w.size();
    int res = helper(w, p, n, cap);
    cout << res;
}

int main()
{
    func();
    return 0;
}
