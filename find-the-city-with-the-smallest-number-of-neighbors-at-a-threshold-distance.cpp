class Solution
{
public:
    int findTheCity(int n, vector<vector<int>> &arr, int l)
    {

        vector<vector<int>> dist(n, vector<int>(n, INT_MAX));

        for (int i = 0; i < arr.size(); i++)
        {

            int u = arr[i][0];
            int v = arr[i][1];
            int w = arr[i][2];
            dist[u][v] = w;
            dist[v][u] = w;
        }
        for (int i = 0; i < n; i++)
        {
            dist[i][i] = 0;
        }
        for (int k = 0; k < n; k++)
        {

            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {

                    if (dist[i][k] == INT_MAX || dist[k][j] == INT_MAX)
                    {
                        continue;
                    }
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
        int cnt = n;
        int res = -1;
        for (int i = 0; i < n; i++)
        {
            int city = 0;
            for (int j = 0; j < n; j++)
            {
                if (dist[i][j] <= l)
                {

                    city++;
                }
            }
            if (city <= cnt)
            {
                cnt = city;
                res = i;
            }
            else if (city == cnt)
            {
                res = min(res, i);
            }
        }
        return res;
    }
};