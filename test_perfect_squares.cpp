#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int helper(int n)

{

    if (n == 0)
    {
        return 0;
    }
    int ans = n;
    for (int i = 1; i * i <= n; i++)
    {
        int temp = i * i;
        ans = min(ans, 1 + helper(n - temp));
    }
    return ans;
}

void func()
{
    vector<int> arr = {1, 2, 5};
    int t = 5;
    int n = 6;
    vector<int> dp(t + 1, 0);
    int res = helper(n);
    cout << res;
}

int main()
{
    func();
    return 0;
}