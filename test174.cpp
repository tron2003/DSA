#include <iostream>
#include <vector>
#include <string>
#include <climits>
using namespace std;

bool isPalindrome(string str, int start, int end)
{
    while (start < end)
    {
        if (str[start] != str[end])
        {
            return false;
        }
        start++;
        end--;
    }
    return true;
}

int minCutPalindromePartition(string str)
{
    int n = str.size();
    vector<int> dp(n, 0);

    for (int i = 0; i < n; i++)
    {
        dp[i] = i; // Maximum cuts needed for the worst case
    }

    for (int i = 1; i < n; i++)
    {
        if (isPalindrome(str, 0, i))
        {
            dp[i] = 0; // No cuts needed if substring [0:i] is a palindrome
            continue;
        }
        for (int j = 0; j < i; j++)
        {
            if (isPalindrome(str, j + 1, i))
            {
                dp[i] = min(dp[i], dp[j] + 1);
            }
        }
    }

    return dp[n - 1];
}

int main()
{
    string str = "aab";
    cout << "Minimum cuts needed for palindrome partitioning: " << minCutPalindromePartition(str) << endl;
    return 0;
}
