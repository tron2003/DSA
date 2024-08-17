/*
    Your Trie object will be instantiated and called as such:
    Trie* obj = new Trie();
    obj->insert(word);
    bool check2 = obj->search(word);
    bool check3 = obj->startsWith(prefix);
 */

class node
{
public:
    int flag = false;
    node *arr[26];
    node *get(char key) { return arr[key - 'a']; }
    bool contain(char key) { return arr[key - 'a'] != NULL; }
    void put(char key, node *temp) { arr[key - 'a'] = temp; }
    void setEnd() { flag = true; }
    bool isEnd() { return flag; }
};
class Trie
{

    node *root;

public:
    /** Initialize your data structure here. */
    Trie() { root = new node(); }

    /** Inserts a word into the trie. */
    void insert(string word)
    {

        node *temp = root;
        for (int i = 0; i < word.size(); i++)
        {
            if (!temp->contain(word[i]))
            {
                temp->put(word[i], new node());
            }
            temp = temp->get(word[i]);
        }
        temp->setEnd();
    }

    /** Returns if the word is in the trie. */
    bool search(string word)
    {
        node *temp = root;
        for (int i = 0; i < word.size(); i++)
        {
            if (!temp->contain(word[i]))
            {
                return false;
            }
            temp = temp->get(word[i]);
        }
        return temp->isEnd();
    }

    /** Returns if there is any word in the trie that starts with the given
     * prefix. */
    bool startsWith(string word)
    {
        node *temp = root;
        for (int i = 0; i < word.size(); i++)
        {
            if (!temp->contain(word[i]))
            {
                return false;
            }
            temp = temp->get(word[i]);
        }
        return true;
        ;
    }
};