#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct tree
{
    tree *child[26];
    bool end; // Use bool to indicate the end of a word

    tree()
    {
        end = false;
        for (int i = 0; i < 26; i++)
        {
            child[i] = NULL;
        }
    }

    ~tree()
    {
        for (int i = 0; i < 26; i++)
        {
            delete child[i];
        }
    }
};

tree *root = new tree(); // Initialize the root of the Trie

void insert(string &key)
{
    tree *curr = root;
    for (int i = 0; i < key.size(); i++)
    {
        int idx = key[i] - 'a';
        if (curr->child[idx] == NULL)
        {
            curr->child[idx] = new tree();
        }
        curr = curr->child[idx];
    }
    curr->end = true;
}

bool search1(string key)
{
    tree *curr = root;
    for (int i = 0; i < key.size(); i++)
    {
        int idx = key[i] - 'a';
        if (curr->child[idx] == NULL)
        {
            return false;
        }
        curr = curr->child[idx];
    }
    return curr->end;
}

// Helper function to check if a node has any children
bool hasChildren(tree *node)
{
    for (int i = 0; i < 26; i++)
    {
        if (node->child[i] != NULL)
        {
            return true;
        }
    }
    return false;
}

// Recursive function to delete a key from the Trie
bool deleteKey(tree *curr, const string &key, int depth = 0)
{
    if (!curr)
    {
        return false;
    }
    if (depth == key.size())
    {
        if (curr->end)
        {
            curr->end = false;
        }
        if (!hasChildren(curr))
        {
            return true;
        }
        return false;
    }
    int idx = key[depth] - 'a';
    if(deleteKey(curr,key,depth+1)){
        delete curr->child[idx];
        curr->child[idx]=NULL;

        return !curr->end && !hasChildren(curr);
    }
    return false;
}

int main()
{
    vector<string> arr = {"bad", "bat", "geek", "geeks", "cat"};
    for (int i = 0; i < arr.size(); i++)
    {
        insert(arr[i]);
    }

    cout << search1("bad") << endl;   // Output: 1 (true)
    cout << search1("bat") << endl;   // Output: 1 (true)
    cout << search1("geek") << endl;  // Output: 1 (true)
    cout << search1("geeks") << endl; // Output: 1 (true)
    cout << search1("cat") << endl;   // Output: 1 (true)
    cout << search1("dog") << endl;   // Output: 0 (false)

    deleteKey(root, "bat");
    cout << search1("bat") << endl; // Output: 0 (false)
    cout << search1("bad") << endl; // Output: 1 (true) - "bad" should still be found

    // Clean up the Trie
    delete root;

    return 0;
}
