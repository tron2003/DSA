#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#define mod 1000000007
long long helper(int n)
{

   
    if (n == 1)
    {
        return 0;
    }
    if (n == 2)
    {
        return 1;
    }
    long long ans = ((n - 1) % mod )* ((helper(n - 2) % mod) + (helper(n - 1) % mod)) % mod;

    return ans;
}

void func()
{
    int n = 1;

    long long res = 0;
    res = helper(n);
    cout << res;
}

int main()
{
    func();
    return 0;
}