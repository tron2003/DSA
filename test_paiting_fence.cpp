#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#define mod 1000000007

long long mul(long long a,long long b){
    return ((a)%mod * (b)%mod) % mod;
}
long long add(long long a,long long b){
    return (a % mod + b % mod) % mod;
}

long long helper(long long a,long long b)
{
  if(a==1){
      return b;
  }
  if(a==2){
      return add(b, mul(b, b - 1));
  }
  return add(mul(helper(a-2,b),b-1), mul(helper(a - 1,b), b - 1));
}

void func()
{
    int n = 3;
    int k =2 ;
    long long res = 0;
    res = helper(n,k);
    cout << res;
}

int main()
{
    func();
    return 0;
}