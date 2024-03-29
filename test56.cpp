#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int func(string &str,string &pat){

    if(str.length()!=pat.length()){
        return false;
    }
    return (str+pat).find(pat)!=string::npos;
}

int main()
{
    string text = "abas";
    string pattern = "abc";
    cout<<func(text, pattern);
    return 0;
}