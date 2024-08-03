#define pa pair<int, pair<int, int>>
class Solution
{
public:
    int minimumEffortPath(vector<vector<int>> &arr)
    {
        priority_queue<pa, vector<pa>, greater<pa>> que;
        int m = arr.size();
        int n = arr[0].size();
        vector<vector<int>> dist(m, vector<int>(n, 1e9));
        dist[0][0] = 0;
        que.push({0, {0, 0}});
        vector<int> row = {0, 0, 1, -1};
        vector<int> col = {1, -1, 0, 0};
        while (!que.empty())
        {
            auto front = que.top();
            int diff = front.first;
            int x = front.second.first;
            int y = front.second.second;
            que.pop();
            if (x == m - 1 && y == n - 1)
            {
                return diff;
            }
            for (int i = 0; i < 4; i++)
            {
                int newx = row[i] + x;
                int newy = col[i] + y;
                if (newx >= 0 && newx < m && newy >= 0 && newy < n)
                {

                    int newdiff = max(abs(arr[newx][newy] - arr[x][y]), diff);
                    if (newdiff < dist[newx][newy])
                    {

                        dist[newx][newy] = newdiff;
                        que.push({newdiff, {newx, newy}});
                    }
                }
            }
        }

        return 0;
    }
};