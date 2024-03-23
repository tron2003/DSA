#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void func(string str1, string str2)
{
    int n = str1.size();
    int m = str2.size();

    for (int i = 0; i < n - m;)
    {

        int j = 0;
        for (j = 0; j < m; j++)
        {
            if (str1[i + j] != str2[j])
            {
                break;
            }
        }
        if (j == m)
        {
            cout << i << endl;
        }
        if (j == 0)
        {
            i++;
        }
        else
        {
            i = i + j;
        }
    }
}

int main()
{
       string str1 = "babcc fsafdas    sdassa";
       string str2 = "babcasdassa       ";
       func(str1,str2);
    return 0;
}