#include <iostream>
#include <vector> // Include the <vector> header for using vectors
using namespace std;

// Function to find the length of the Longest Common Subsequence (LCS) of two strings
// s1 and s2, using memoization to optimize repeated subproblem computations
int func(string s1, string s2, int m, int n, vector<vector<int>> dp)
{
    // Base cases:
    if (m == 0 || n == 0)
    {
        return 0; // Return 0 directly for the base case
    }
    
    if (s1[m - 1] == s2[n - 1])
    {
        dp[m][n] = 1 + func(s1, s2, m - 1, n - 1, dp);
    }
    // If the result is already computed, return it from the memoization table

    if (dp[m][n] != -1)
    {
        return dp[m][n];
    }
    // If the characters at the current positions of both strings match,
    // increment the LCS length by 1 and recursively call func with decremented indices
   
    else
    {
        // If the characters don't match, recursively call func for both possibilities:
        // 1. Exclude the last character of s1 and recur
        // 2. Exclude the last character of s2 and recur
        // Choose the maximum of these two results
        return dp[m][n] = max(func(s1, s2, m - 1, n, dp), func(s1, s2, m, n - 1, dp));
    }
}

int main()
{
    // Input strings
    string X = "AGGAB";
    string Y = "GXTXAYB";

    // Lengths of the input strings
    int m = X.length();
    int n = Y.length();

    // Initialize the memoization table
    vector<vector<int>> dp(m+1 , vector<int>(n+1 , -1));

    // Call the function to compute the length of LCS
    cout << "Length of Longest Common Subsequence: " << func(X, Y, m, n, dp) << endl;

    return 0;
}
