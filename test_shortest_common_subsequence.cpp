#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    string shortestCommonSupersequence(string str1, string str2)
    {
        int m = str1.size();
        int n = str2.size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

        // Fill the dp table for LCS
        for (int i = 1; i <= m; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (str1[i - 1] == str2[j - 1])
                {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                }
                else
                {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }

        // Backtrack to construct the shortest common supersequence
        string res = "";
        int i = m, j = n;
        while (i > 0 && j > 0)
        {
            if (str1[i - 1] == str2[j - 1])
            {
                res += str1[i - 1];
                i--;
                j--;
            }
            else if (dp[i - 1][j] > dp[i][j - 1])
            {
                res += str1[i - 1];
                i--;
            }
            else
            {
                res += str2[j - 1];
                j--;
            }
        }

        // Add remaining characters from str1 and str2
        while (i > 0)
        {
            res += str1[i - 1];
            i--;
        }
        while (j > 0)
        {
            res += str2[j - 1];
            j--;
        }

        // Reverse the result as we constructed it backwards
        reverse(res.begin(), res.end());
        return res;
    }
};

int main()
{
    Solution sol;
    string str1 = "abac";
    string str2 = "cab";

    string result = sol.shortestCommonSupersequence(str1, str2);
    cout << "Shortest Common Supersequence: " << result << endl; // Expected: "cabac"

    return 0;
}
