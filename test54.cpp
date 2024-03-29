#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void fillps(string str, int lps[]) {
    int n = str.length();
    int len = 0;
    int i = 1;
    lps[0] = 0;
    while (i < n) {
        if (str[i] == str[len]) {
            len++;
            lps[i] = len;
            i++;
        }
        else {
            if (len == 0) {
                lps[i] = 0;
                i++;
            }
            else {
                len = lps[len - 1];
            }
        }
    }
}

int main() {
    string text = "ababcababcabcabc";
    int arr[text.size()];
    fillps(text, arr);

    // Print the lps array
    cout << "Longest Prefix and Suffix Array (lps): ";
    for (int i = 0; i < text.size(); ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0; 
}