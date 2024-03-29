#include <iostream>
#include <bits/stdc++.h>
using namespace std;
void fillps(string str, int lps[])
{
    int n = str.length();
    int len = 0;
    int i = 1;
    lps[0] = 0;
    while (i < n)
    {
        if (str[i] == str[len])
        {
            len++;
            lps[i] = len;
            i++;
        }
        else
        {
            if (len == 0)
            {
                lps[i] = 0;
                i++;
            }
            else
            {
                len = lps[len - 1];
            }
        }
    }
}

void func(string str, string pat, int n, int m)
{
    int lps[m];

    fillps(pat,lps);
    int i =0;
    int j =0;

    while(i<n){
        if(pat[j]==str[i]){
            i++;j++;
        }
        if(j==m){
            cout<<i-j<<endl;
            j = lps[j-1];
        }
        else if(i< n&& pat[j]!=str[i]){
            if(j==0){
                i++;
            }
            else {
                j = lps[j-1];
            }
        }
    }
}

int main()
{
    string text = "ababcababcabcabc";
    string pattern = "abc";
    func(text, pattern, text.size(), pattern.size());
    return 0;
}