#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define CHAR 256

void reverse(string &s,int i ,int j){

    while(i<=j){

        swap(s[i],s[j]);
        i++;
        j--;
    }
}
void func(string &s1)
{
    int start = 0;
    for (int i = 0; i < s1.size(); i++)
    {

        if (s1[i] == ' ')
        {
            reverse(s1, start, i - 1);
            start = i + 1;
        }
    }
    reverse(s1,start,s1.size()-1);
    reverse(s1,0,s1.size()-1);


    cout << s1 << endl;
}

int main()
{
    string str1 = "babcc fsafdas    sdassa";

    func(str1);
    return 0;
}