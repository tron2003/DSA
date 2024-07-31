class Solution
{
public:
    void bfs(vector<vector<char>> &arr, vector<vector<int>> &vis, int i,
             int j)
    {

        vis[i][j] = 1;
        queue<pair<int, int>> que;
        que.push({i, j});
        while (!que.empty())
        {

            int s = que.front().first;
            int e = que.front().second;
            que.pop();
            int dRow[] = {
                -1,
                1,
                0,
                0,
            };
            int dCol[] = {
                0,
                0,
                -1,
                1,
            };
            int n = arr.size();
            int m = arr[0].size();
            for (int k1 = 0; k1 <= 3; k1++)
            {

                int nrow = s + dRow[k1];
                int ncol = e + dCol[k1];
                if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m &&
                    arr[nrow][ncol] == '1' && !vis[nrow][ncol])
                {

                    vis[nrow][ncol] = 1;
                    que.push({nrow, ncol});
                }
            }
        }
    }

    int numIslands(vector<vector<char>> &arr)
    {
        int n = arr.size();
        int m = arr[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        int res = 0;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {

                if (arr[i][j] == '1' && !vis[i][j])
                {
                    res++;
                    bfs(arr, vis, i, j);
                }
            }
        }
        return res;
    }
};