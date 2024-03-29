#include <iostream>
#include <string>
#include <cmath>

using namespace std;

// Function to calculate the hash value of a string
int hashString(const string& s, int prime, int modulus) {
    int hashVal = 0;
    for (char c : s) {
        hashVal = (hashVal * prime + c) % modulus;
    }
    return hashVal;
}

// Function to implement Rabin-Karp algorithm
void rabinKarp(const string& text, const string& pattern) {
    int prime = 101;  // A prime number used for hashing
    int modulus = 1e9 + 7;  // A large prime number used for modulo operation
    int n = text.length();
    int m = pattern.length();
    int patternHash = hashString(pattern, prime, modulus);
    int textHash = hashString(text.substr(0, m), prime, modulus);

    for (int i = 0; i <= n - m; ++i) {
        if (textHash == patternHash) {
            bool match = true;
            for (int j = 0; j < m; ++j) {
                if (text[i + j] != pattern[j]) {
                    match = false;
                    break;
                }
            }
            if (match) {
                cout << "Pattern found at index " << i << endl;
            }
        }
        if (i < n - m) {
            // Update hash value for the next window
            textHash = (textHash - text[i] * (int)pow(prime, m - 1)) * prime + text[i + m];
            textHash %= modulus;
            if (textHash < 0) {
                textHash += modulus;  // Adjust negative values
            }
        }
    }
}

int main() {
    string text = "ababcababcabcabc";
    string pattern = "abc";
    rabinKarp(text, pattern);
    return 0;
}
