#define p pair<int, int>
#define pa pair<int, p>
class Solution
{
public:
    int shortestPath(vector<vector<int>> &grid, pair<int, int> src,
                     pair<int, int> dist)
    {

        priority_queue<pa, vector<pa>, greater<pa>> que;
        int m = grid.size();
        int n = grid[0].size();
        if (src.first == dist.first && dist.second == src.second)
        {
            return 0;
        }
        vector<vector<int>> vis(m, vector<int>(n, 1e9));
        que.push({0, {src.first, src.second}});
        vis[src.first][src.second] = 0;
        vector<int> row = {0, 0, -1, 1};
        vector<int> col = {1, -1, 0, 0};
        while (!que.empty())
        {

            auto front = que.top();
            int wgt = front.first;
            int r = front.second.first;
            int c = front.second.second;
            que.pop();
            for (int i = 0; i < 4; i++)
            {
                int newr = row[i] + r;
                int newc = col[i] + c;

                // int w = grid[]
                if (newr >= 0 && newr < m && newc >= 0 && newc < n && grid[newr][newc] == 1 && wgt + 1 < vis[newr][newc])
                {

                    vis[newr][newc] = wgt + 1;
                    if (newr == dist.first && newc == dist.second)
                    {
                        return vis[newr][newc];
                    }
                    grid[newr][newc] = 0;

                    que.push({vis[newr][newc], {newr, newc}});
                }
            }
        }

        return -1;
        // code here
    }
};