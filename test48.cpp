#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define CHAR 256
bool func(string s1, string s2)
{

    if (s1.length() != s2.length())
    {

        return false;
    }
    int count[CHAR] = {0};

    for (int i = 0; i < s1.length(); i++)
    {

        count[s2[i]]++;
        count[s1[i]]--;
    }
    for (auto x : count)
    {
        if (x  != 0)
        {
            return false;
        }
    }
    return true;
}

int main()
{
    string str1 = "a121";
    string str2 = "121a";
    cout << func(str1, str2);
    return 0;
}