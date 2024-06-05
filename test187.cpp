#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void helper(string str, int idx)
{

    if (idx >= str.size())
    {

        cout << str << " ";
        return;
    }
    for (int i = idx; i < str.size(); i++)
    {

        swap(str[i], str[idx]);
        helper(str, idx + 1);
        // swap(str[i], str[idx]);
    }
}
void func(string str)
{

    string temp = "";
    helper(str, 0);
   
}

int main()
{
    string str = "abc";

    func(str);
    return 0;
}