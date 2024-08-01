class Solution
{
public:
    vector<int> eventualSafeNodes(vector<vector<int>> &arr)
    {

        unordered_map<int, list<int>> mp;
        int n = arr.size();
        vector<int> res;
        vector<int> ind(n, 0);
        for (int i = 0; i < n; i++)
        {

            int u = i;
            // int m = arr[i].size();
            for (auto v : arr[u])
            {

                mp[v].push_back(u);
                ind[u]++;
            }
        }
        queue<int> que;
        for (int i = 0; i < n; i++)
        {

            if (ind[i] == 0)
            {

                que.push(i);
            }
        }
        while (!que.empty())
        {

            int temp = que.front();
            que.pop();
            res.push_back(temp);
            for (auto ne : mp[temp])
            {

                ind[ne]--;
                if (ind[ne] == 0)
                {
                    que.push(ne);
                }
            }
        }

        sort(res.begin(), res.end());
        return res;
    }
};