#define pa pair<int, int>
class Solution
{
public:
    /*  Function to implement Bellman Ford
     *   edges: vector of vectors which represents the graph
     *   S: source vertex to start traversing graph with
     *   V: number of vertices
     */
    vector<int> bellman_ford(int v, vector<vector<int>> &arr, int src)
    {
        // Code here

        vector<int> dist(v, 1e8);
        dist[src] = 0;
        for (int i = 0; i < v - 1; i++)
        {

            for (auto x : arr)
            {
                int u = x[0];
                int v = x[1];
                int wgt = x[2];
                if (dist[u] + wgt < dist[v] && dist[u] != 1e8)
                {

                    dist[v] = dist[u] + wgt;
                }
            }
        }
        for (auto x : arr)
        {
            int u = x[0];
            int v = x[1];
            int wgt = x[2];
            if (dist[u] + wgt < dist[v] && dist[u] != 1e8)
            {

                return {-1};
            }
        }

        return dist;
    }
};