#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#define mod 1000000007
long long helper( int n)
{

    int temp1 = 0;
    int temp2 = 1;
  

    for (int i = 3; i <= n; i++)
    {
        temp2 = temp2 % mod;
        temp1 = temp1 % mod;

        int ans = (i-1)*(temp1 + temp2) % mod;
        temp1 = temp2;
        temp2 = ans;
    }
    return temp2;
}

void func()
{
    int n = 5;

    long long res = 0;
    vector<long long> dp(n + 1, INT_MIN);
    res = helper( n);
    cout << res;
}

int main()
{
    func();
    return 0;
}