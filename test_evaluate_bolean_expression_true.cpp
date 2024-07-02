#include <iostream>
#include <string>
#include <vector>

using namespace std;

typedef long long ll;
const ll mod = 1003; // Adjusted modulo for small constraints

ll helper(string &str, ll i, ll j, bool istrue, vector<vector<vector<ll>>> &dp)
{
    if (i > j)
    {
        return 0;
    }
    if (i == j)
    {
        if (istrue)
        {
            return str[i] == 'T';
        }
        else
        {
            return str[i] == 'F';
        }
    }
    if (dp[i][j][istrue] != -1)
    {
        return dp[i][j][istrue];
    }
    ll ways = 0;
    for (ll k = i + 1; k <= j - 1; k += 2)
    {
        ll lt = helper(str, i, k - 1, true, dp) % mod;
        ll lf = helper(str, i, k - 1, false, dp) % mod;
        ll rt = helper(str, k + 1, j, true, dp) % mod;
        ll rf = helper(str, k + 1, j, false, dp) % mod;

        if (str[k] == '&')
        {
            if (istrue)
            {
                ways = (ways + (lt * rt) % mod) % mod;
            }
            else
            {
                ways = (ways + (lt * rf) % mod + (lf * rt) % mod + (lf * rf) % mod) % mod;
            }
        }
        else if (str[k] == '|')
        {
            if (istrue)
            {
                ways = (ways + (lt * rt) % mod + (lt * rf) % mod + (lf * rt) % mod) % mod;
            }
            else
            {
                ways = (ways + (lf * rf) % mod) % mod;
            }
        }
        else if (str[k] == '^')
        {
            if (istrue)
            {
                ways = (ways + (lt * rf) % mod + (lf * rt) % mod) % mod;
            }
            else
            {
                ways = (ways + (lt * rt) % mod + (lf * rf) % mod) % mod;
            }
        }
    }
    return dp[i][j][istrue] = ways % mod;
}

int countWays(int n, string str)
{
    vector<vector<vector<ll>>> dp(n, vector<vector<ll>>(n, vector<ll>(2, -1)));
    ll res = helper(str, 0, n - 1, true, dp);
    return (int)res; // Convert result to int as required
}

int main()
{
    int n;
    cin >> n;
    string str;
    cin >> str;
    int result = countWays(n, str);
    cout << result << endl;
    return 0;
}
