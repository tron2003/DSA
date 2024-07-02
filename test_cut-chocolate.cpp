#include <bits/stdc++.h>
int helper(vector<int> &arr, int i, int j, vector<vector<int>> &dp) {

  if (i > j) {

    return 0;
  }
  if (dp[i][j] != -1) {

    return dp[i][j];
  }
  int mini = 1e9;
  for (int k = i; k <= j; k++) {
    int temp = arr[j + 1] - arr[i - 1] + helper(arr, i, k - 1, dp) +
               helper(arr, k + 1, j, dp);
    mini = min(temp, mini);
  }
  return dp[i][j] = mini;
}
int cost(int n, int c, vector<int> &cuts) {

  cuts.push_back(n);
  cuts.insert(cuts.begin(), 0);
  sort(cuts.begin(), cuts.end());
  vector<vector<int>> dp(c + 2, vector<int>(c + 2, 0));
  for (int i = c; i >= 1; i--) {
    for (int j = 1; j <= c; j++) {

      if (i > j) {
        continue;
      }
      int mini = 1e9;
      for (int k = i; k <= j; k++) {
        int temp = cuts[j + 1] - cuts[i - 1] + dp[i][k - 1] + dp[k + 1][j];
        mini = min(temp, mini);
      }
      dp[i][j] = mini;
    }
  }
  //   int res = helper(cuts, 1, c, dp);
  return dp[1][c];
  // Write your code here.
}