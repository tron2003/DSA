#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int fact(int n)
{

    if (n <= 1)
    {
        return 1;
    }
    return n * fact(n - 1);
}
int func(string &str)
{

    int n = str.size();
    int mul = fact(n);
    int count[256] = {0};
    int res = 1;
    for (int i = 0; i < n; i++)
    {
        count[str[i]]++;
    }
    for (int i = 1; i < 256; i++)
    {
        count[i] = count[i] + count[i - 1];
    }

    for(int i =0;i<n-1;i++){

        mul = mul/(n-i);
        res= res+(count[str[i]-1]*mul);
        for(int j = str[i];j<=256;j++){

            count[j]--;
        }
    }

    return res;
}

int main()
{   string str = "BAC";
    cout<<func(str);
    return 0;
}