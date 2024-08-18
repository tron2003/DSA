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

int maximumXor(vector<int> arr)
{
    // Write your code here.
    Trie tree;
    for (auto x : arr)
    {
        tree.insert(x);
    }
    int res = 0;
    for (auto x : arr)
    {
        int temp = tree.getmax(x);
        res = max(res, temp);
    }
    return res;
}