class Solution
{
public:
    void topo(unordered_map<int, list<int>> &mp, vector<int> &ind, vector<int> &res, int k)
    {

        queue<int> que;
        for (int i = 0; i < k; i++)
        {
            if (ind[i] == 0)
            {
                que.push(i);
            }
        }
        while (!que.empty())
        {

            auto temp = que.front();
            que.pop();
            res.push_back(temp);
            for (auto n : mp[temp])
            {
                ind[n]--;
                if (ind[n] == 0)
                {
                    que.push(n);
                }
            }
        }
    }
    string findOrder(string str[], int n, int k)
    {
        // code here
        unordered_map<int, list<int>> mp;
        vector<int> vis(k, 0);
        for (int i = 0; i < n - 1; i++)
        {

            string str1 = str[i];
            string str2 = str[i + 1];
            int m = min(str1.size(), str2.size());
            for (int p = 0; p < m; p++)
            {

                if (str1[p] != str2[p])
                {
                    mp[str1[p] - 'a'].push_back(str2[p] - 'a');
                    vis[str2[p] - 'a']++;
                    break;
                }
            }
        }
        vector<int> res;
        topo(mp, vis, res, k);
        string temp = "";
        for (auto x : res)
        {

            temp += char(x + 'a');
        }

        return temp;
    }
};