class Solution
{
public:
    void dfs(vector<vector<int>> &arr, vector<vector<int>> &vis, int i, int j,
             int m, int n)
    {

        if (i < 0 || i >= m || j < 0 || j >= n || vis[i][j] == 1 ||
            arr[i][j] == 0)
        {
            return;
        }
        vis[i][j] = 1;
        vector<int> drow = {0, 0, 1, -1};
        vector<int> dcol = {1, -1, 0, 0};
        for (int k = 0; k < 4; k++)
        {

            int x = drow[k] + i;

            int y = dcol[k] + j;
            dfs(arr, vis, x, y, m, n);
        }
    }
    int numEnclaves(vector<vector<int>> &arr)
    {

        int m = arr.size();
        int n = arr[0].size();
        int res = 0;
        vector<vector<int>> vis(m, vector<int>(n, 0));
        // top down left
        for (int i = 0; i < m; i++)
        {
            int j = 0;
            if (arr[i][j] == 1 && !vis[i][j])
            {
                dfs(arr, vis, i, j, m, n);
            }
        }
        // left right top
        for (int j = 0; j < n; j++)
        {
            int i = 0;
            if (arr[i][j] == 1 && !vis[i][j])
            {
                dfs(arr, vis, i, j, m, n);
            }
        }
        // top down right
        for (int i = 0; i < m; i++)
        {
            int j = n - 1;
            if (arr[i][j] == 1 && !vis[i][j])
            {
                dfs(arr, vis, i, j, m, n);
            }
        }
        // left rigth last
        for (int j = 0; j < n; j++)
        {
            int i = m - 1;
            if (arr[i][j] == 1 && !vis[i][j])
            {
                dfs(arr, vis, i, j, m, n);
            }
        }
        for (int i = 0; i < m; i++)
        {

            for (int j = 0; j < n; j++)
            {
                if (arr[i][j] == 1 && vis[i][j] == 0)
                {
                    res++;
                }
            }
        }

        return res;
    }
};