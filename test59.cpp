#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int func(string &str)
{
    int n = str.size();
    vector<int> prev(256, -1);
    int i = 0;
    int res = 0;
    for (int j = 0; j < n; j++)
    {
        i = max(i, prev[str[j]]);
        int maxend = j - i + 1;
        res = max(res, maxend);
        prev[str[j]] = j;
    }

    return res;
}

int main()
{
   string str = "BADCAA";
    cout<<func(str);
    return 0;
}