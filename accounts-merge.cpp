class Solution
{
public:
    void unionbysize(vector<int> &rankbysize, vector<int> &parent, int u,
                     int v)
    {

        int u_parent = find(rankbysize, parent, u);
        int v_parent = find(rankbysize, parent, v);
        if (u_parent == v_parent)
        {
            return;
        }
        if (rankbysize[u_parent] > rankbysize[v_parent])
        {

            rankbysize[u_parent] += rankbysize[v_parent];
            parent[v_parent] = u_parent;
        }
        else
        {
            rankbysize[v_parent] += rankbysize[u_parent];
            parent[u_parent] = v_parent;
        }
    }
    int find(vector<int> &rankbysize, vector<int> &parent, int node)
    {

        if (node == parent[node])
        {
            return node;
        }
        return parent[node] = find(rankbysize, parent, parent[node]);
    }
    vector<vector<string>> accountsMerge(vector<vector<string>> &arr)
    {
        int n = arr.size();
        vector<int> rank(n, 1);
        vector<int> parent(n, 0);
        for (int i = 0; i < n; i++)
        {
            parent[i] = i;
        }
        unordered_map<string, int> mp;
        for (int i = 0; i < n; i++)
        {
            for (int j = 1; j < arr[i].size(); j++)
            {
                string temp = arr[i][j];
                if (mp.find(temp) == mp.end())
                {
                    mp[temp] = i;
                }
                else
                {
                    unionbysize(rank, parent, i, mp[temp]);
                }
            }
        }
        vector<string> merge[n];
        for (auto x : mp)
        {
            string mail = x.first;
            int node = find(rank, parent, x.second);
            merge[node].push_back(mail);
        }
        vector<vector<string>> res;
        for (int i = 0; i < n; i++)
        {
            if (merge[i].size() == 0)
            {
                continue;
            }
            sort(merge[i].begin(), merge[i].end());
            vector<string> temp;
            temp.push_back(arr[i][0]);
            for (auto x : merge[i])
            {
                temp.push_back(x);
            }
            res.push_back(temp);
        }
        return res;
    }
};