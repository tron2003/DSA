#include <iostream>
#include <bits/stdc++.h>
using namespace std;

bool issafe(string str, int l, int i)
{

    if (l != 0 && str[l - 1] == 'A' && str[l] == 'B')
    {
        return false;
    }
    if (i == l + 1 && str[l] == 'A' && str[i] == 'B')
    {
        return false;
    }
    return true;
}

void func(string str, int l, int r)
{
    if (l == r)
    {
        cout << str << endl;
        return;
    }
    else
    {
        for (int i = l; i <= r; i++)
        {  if(issafe(str,l,r)){
            swap(str[l], str[i]);

            func(str, l + 1, r);
            swap(str[l], str[i]);

        }

        }
    }
}

int main()
{
    string str = "ABC";
    func(str, 0, 2);
    return 0;
}