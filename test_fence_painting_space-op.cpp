#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#define mod 1000000007

long long mul(long long a, long long b)
{
    return ((a) % mod * (b) % mod) % mod;
}
long long add(long long a, long long b)
{
    return (a % mod + b % mod) % mod;
}

long long helper(long long n, vector<long long> &dp, long long k)
{


    int temp1  = k;
    int temp2 = add(k , mul(k,(k - 1)));
    for (int i = 3; i <= n; i++)
    {

        temp1 = mul(temp1, k - 1);
        temp2 = mul(temp2, k - 1);
         
        int ans = add(temp1,temp2);
        temp1 = temp2;
        temp2 = ans;
    }
    return temp2;
    
}

void func()
{
    int n = 3;
    int k = 2;
    long long res = 0;
    vector<long long> dp(n + 1, 0);
    res = helper(n, dp, k);
    cout << res;
}

int main()
{
    func();
    return 0;
}