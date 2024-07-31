class Solution
{
public:
    void dfs(int i, int j, vector<vector<int>> &arr, vector<vector<int>> &vis, vector<pair<int, int>> &temp, int row, int col)

    {
        // code here
        int m = arr.size();
        int n = arr[0].size();
        vis[i][j] = 1;
        vector<int> drow = {0, 0, 1, -1};
        vector<int> dcol = {1, -1, 0, 0};
        temp.push_back({i - row, j - col});
        for (int k = 0; k < 4; k++)
        {

            int x = drow[k] + i;
            int y = dcol[k] + j;
            if (x >= 0 && x <= m - 1 && y >= 0 && y <= n - 1 && vis[x][y] == 0 && arr[x][y] == 1)
            {

                dfs(x, y, arr, vis, temp, row, col);
            }
        }
    }

    int countDistinctIslands(vector<vector<int>> &arr)
    {
        // code here
        int m = arr.size();
        int n = arr[0].size();
        set<vector<pair<int, int>>> st;
        vector<vector<int>> vis(m, vector<int>(n, 0));

        for (int i = 0; i < m; i++)
        {

            for (int j = 0; j < n; j++)
            {
                if (!vis[i][j] && arr[i][j] == 1)
                {

                    vector<pair<int, int>> temp;
                    dfs(i, j, arr, vis, temp, i, j);
                    st.insert(temp);
                }
            }
        }

        return st.size();
    }
};