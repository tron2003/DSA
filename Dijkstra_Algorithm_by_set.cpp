#define pa pair<int, int>
class Solution
{
public:
    // Function to find the shortest distance of all the vertices
    // from the source vertex S.
    vector<int> dijkstra(int v, vector<vector<int>> arr[], int s)
    {
        // Code here
        set<pa> set;
        vector<int> dist(v, 1e9);
        dist[s] = 0;
        set.insert({0, s});
        while (set.size() != 0)
        {

            auto fron = *set.begin();
            set.erase(fron);
            int u = fron.second;
            int till = fron.first;
            for (auto x : arr[u])
            {
                int v = x[0];
                int vwght = x[1];

                if (till + vwght < dist[v])
                {

                    dist[v] = till + vwght;
                    set.insert({dist[v], v});
                }
            }
        }

        return dist;
    }
};
