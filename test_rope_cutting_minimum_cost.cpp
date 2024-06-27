class Solution
{
public:
    int helper(int arr[], int tar, int i, vector<vector<int>> &dp)
    {

        if (tar < 0)
        {
            return INT_MIN; // Return a very low value to indicate an invalid solution
        }
        if (tar == 0)
        {
            return 0; // If the target is achieved, return 0 profit as there are no more cuts needed
        }
        if (i < 0)
        {
            return INT_MIN; // If no items are left and target is not achieved, return invalid
        }
        if (dp[tar][i] != -1)
        {
            return dp[tar][i];
        }

        int sub = i + 1;
        int inc = arr[i] + helper(arr, tar - sub, i, dp); // Including the current piece
        int exe = helper(arr, tar, i - 1, dp);            // Excluding the current piece

        return dp[tar][i] = max(inc, exe); // Return the maximum of including or excluding the current piece
    }

    int cutRod(int price[], int n)
    {
        // code here
        int k = sizeof(price) / sizeof(price[0]);
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
        int res = helper(price, n, n - 1, dp);
        return res;
    }
};