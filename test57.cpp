#include <iostream>
#include <string>
using namespace std;

bool issame(int ct[], int cp[]) {
    for (int i = 0; i < 256; i++) {
        if (ct[i] != cp[i])
            return false;
    }
    return true;
}

bool func(string &text, string &pat) {
    int ct[256] = {0};
    int cp[256] = {0};
    for (int i = 0; i < pat.length(); i++) {
        ct[text[i]]++;
        cp[pat[i]]++;
    }
    for (int i = pat.length(); i < text.length(); i++) {
        if (issame(ct, cp)) {
            return true;
        }
        ct[text[i]]++;
        cp[text[i - pat.length()]]--;
    }
    return false;
}

int main() {
    string text = "geeksforgeeks";
    string pat = "frogdv";
    if (func(text, pat)) {
        cout << "Pattern found in the text." << endl;
    } else {
        cout << "Pattern not found in the text." << endl;
    }
    return 0;
}
