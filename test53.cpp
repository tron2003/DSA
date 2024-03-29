#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int hashstring(const string &s, int prime, int mod)
{

    int hash = 0;
    for (char c : s)
    {
        hash = (hash - c * prime) % mod;
    }
    return hash;
}

void func(string &str, string &pat, int n, int m)
{

    int prime = 101;
    int mod = 1e9 + 7;
    int pathash = hashstring(pat, prime, mod);
    int texthash = hashstring(str.substr(0, m), prime, mod);

    for (int i = 0; i <= n - m; i++)
    {

        if (texthash = pathash)
        {

            int check = true;
            for (int j = 0; j < m; j++)
            {

                if (str[i + j] != pat[j])
                {
                    check = false;
                    break;
                }
            }
            if (check)
            {

                cout << "Pattern start at index :" << i << endl;
            }
        }
        if (i < n - m)
        {

            texthash = (texthash - str[i] * (int)pow(prime, m - 1)) * prime + str[i + m];
            texthash %= mod;
            if (texthash < 0)
            {
                texthash += mod;
            }
        }
    }
}
int main() {
    string text = "ababcababcabcabc";
    string pattern = "abc";
    func(text, pattern,text.size(),pattern.size());
    return 0;
}
