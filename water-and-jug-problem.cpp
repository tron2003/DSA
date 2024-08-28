class Solution
{
public:
    bool dfs(int total, int jug1, int jug2, int jug, int target, vector<int> &vis, vector<int> &dp)
    {
        if (jug > total || jug < 0 || vis[jug] == 1)
            return false;
        if (dp[jug] != -1)
        {
            return dp[jug];
        }
        vis[jug] = 1;
        if (jug == target)
            return true;
        bool a = dfs(total, jug1, jug2, jug + jug1, target, vis, dp);
        bool b = dfs(total, jug1, jug2, jug - jug1, target, vis, dp);
        bool c = dfs(total, jug1, jug2, jug + jug2, target, vis, dp);
        bool d = dfs(total, jug1, jug2, jug - jug2, target, vis, dp);
        return a || b || c || d;
    }
    bool canMeasureWater(int jug1Capacity, int jug2Capacity, int targetCapacity)
    {
        int total = jug1Capacity + jug2Capacity;
        vector<int> vis(total + 1, 0);
        vector<int> dp(total + 1, -1);
        return dfs(total, jug1Capacity, jug2Capacity, 0, targetCapacity, vis, dp);
    }
};