class node
{

public:
    node *arr[2];
    void put(int key, node *temp) { arr[key] = temp; }
    bool contain(int key) { return arr[key] != NULL; }
    node *get(int key) { return arr[key]; }
};

class Trie
{

public:
    node *root;
    Trie() { root = new node(); }

    void insert(int num)
    {

        node *temp = root;
        for (int i = 31; i >= 0; i--)
        {

            int bit = (num >> i) & 1;
            if (!temp->contain(bit))
            {

                temp->put(bit, new node());
            }
            temp = temp->get(bit);
        }
    }
    int getmax(int num)
    {
        int max1 = 0;
        node *temp = root;
        for (int i = 31; i >= 0; i--)
        {
            int bit = (num >> i) & 1;
            if (temp->contain(1 - bit))
            {
                max1 = max1 | (1 << i);
                temp = temp->get(1 - bit);
            }
            else
            {
                temp = temp->get(bit);
            }
        }
        return max1;
    }
};

class Solution
{
public:
    vector<int> maximizeXor(vector<int> &arr, vector<vector<int>> &queries)
    {
        sort(arr.begin(), arr.end());
        vector<pair<int, pair<int, int>>> que;

        int n = queries.size();
        for (int i = 0; i < n; i++)
        {

            que.push_back({queries[i][1], {queries[i][0], i}});
        }

        sort(que.begin(), que.end());

        vector<int> res(n, 0);
        int idx = 0;
        Trie tree;
        int temp = arr.size();
        for (int i = 0; i < n; i++)
        {

            int ai = que[i].first;
            int xi = que[i].second.first;
            int qidx = que[i].second.second;
            while (idx < temp && arr[idx] <= ai)
            {

                tree.insert(arr[idx]);
                idx++;
            }
            if (idx == 0)
            {
                res[qidx] = -1;
            }
            else
            {
                res[qidx] = tree.getmax(xi);
            }
        }
        return res;
    }
};