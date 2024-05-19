#include <iostream>
#include <vector>
#include <climits> // For INT_MAX
using namespace std;

int func(vector<int> arr, int n)
{
    vector<vector<int>> dp(n, vector<int>(n, 0));

    // Chain length "gap" starts from 2
    for (int gap = 2; gap < n; gap++)
    {
        for (int i = 0; i + gap < n; i++)
        {
            int j = i + gap;
            dp[i][j] = INT_MAX; // Initialize with maximum value

            // Try all possible splits for the chain (i, j)
            for (int k = i + 1; k < j; k++)
            {
                // Calculate cost of the split (i, k) and (k, j)
                int cost = dp[i][k] + dp[k][j] + arr[i] * arr[k] * arr[j];
                dp[i][j] = min(dp[i][j], cost);
            }
        }
    }
    return dp[0][n - 1]; // Return cost of multiplying entire chain
}

int main()
{
    cout << func({2, 1, 3, 4}, 4) << endl;
    return 0;
}
