#include <bits/stdc++.h>
using namespace std;

// int helper(int n, vector<vector<int>> arr, int i, int last) {

//   if (i == 0) {
//     int temp = 0;
//     for (int j = 0; j < 3; j++) {
//       if (j != last) {
//         temp = max(arr[i][j], temp);
//       }
//     }
//     return temp;
//   }
//   int temp = 0;
//   for (int j = 0; j < 3; j++) {
//     if (j != last) {

//       int temp1 = arr[i][j] + helper(n, arr, i - 1, j);
//       temp = max(temp1, temp);
//     }
//   }
//   return temp;
// }

// int helper(int n, vector<vector<int>> &arr, vector<vector<int>> &dp, int i,
//            int last) {

//   if (i == 0) {
//     int temp = 0;
//     for (int j = 0; j < 3; j++) {
//       if (j != last) {
//         temp = max(arr[i][j], temp);
//       }
//     }
//     return temp;
//   }
//   if (dp[i][last] != -1) {

//     return dp[i][last];
//   }
//   int temp = 0;
//   for (int j = 0; j < 3; j++) {
//     if (j != last) {

//       int temp1 = arr[i][j] + helper(n, arr, dp, i - 1, j);
//       temp = max(temp1, temp);
//     }
//   }
//   dp[i][last] = temp;
//   return temp;
// }
// int helper(int n, vector<vector<int>> &arr, int i, int last) {

//   vector<vector<int>> dp(n + 1, vector<int>(4, 0));
//   dp[0][0] = max(arr[0][1], arr[0][2]);
//   dp[0][1] = max(arr[0][0], arr[0][2]);
//   dp[0][2] = max(arr[0][1], arr[0][0]);
//   dp[0][3] = max({arr[0][1], arr[0][1], arr[0][2]});
//   for (int i = 1; i < n; i++) {
//     for (int k = 0; k < 4; k++) {
//       dp[i][k] = 0;

//       for (int j = 0; j < 3; j++) {
//         if (j != k) {

//           int temp = arr[i][j] + dp[i - 1][j];

//               dp[i][k] = max(dp[i][k], temp);
//         }
//       }
//     }
//   }

//   return dp[n-1][3];
// }

int helper(int n, vector<vector<int>> &arr, int i, int last)
{

    vector<vector<int>> dp(n + 1, vector<int>(4, 0));
    vector<int> prev(4, 0);
    vector<int> curr(4, 0);
    prev[0] = max(arr[0][1], arr[0][2]);
    prev[1] = max(arr[0][0], arr[0][2]);
    prev[2] = max(arr[0][1], arr[0][0]);
    prev[3] = max({arr[0][1], arr[0][1], arr[0][2]});
    for (int i = 1; i < n; i++)
    {
        for (int k = 0; k < 4; k++)
        {
            curr[k] = 0;

            for (int j = 0; j < 3; j++)
            {
                if (j != k)
                {

                    int temp = arr[i][j] + prev[j];

                    curr[k] = max(curr[k], temp);
                }
            }
        }
        prev = curr;
    }

    return curr[3];
}
int ninjaTraining(int n, vector<vector<int>> &points)
{
    vector<vector<int>> dp(n, vector<int>(4, -1));
    int res = helper(n, points, n - 1, 3);

    return res;
}