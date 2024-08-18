
class node
{

public:
    node *arr[26];
    node *get(char key) { return arr[key - 'a']; }
    void put(char key, node *temp) { arr[key - 'a'] = temp; }
    bool contain(char key) { return arr[key - 'a'] != NULL; }
};

int countDistinctSubstrings(string &s)
{

    int cnt = 0;
    int n = s.size();
    node *root = new node();
    for (int i = 0; i < n; i++)
    {

        node *temp = root;
        for (int j = i; j < n; j++)
        {

            if (!temp->contain(s[j]))
            {

                cnt++;
                temp->put(s[j], new node());
            }
            temp = temp->get(s[j]);
        }
    }
    return cnt + 1;

    //    Write your code here.
}