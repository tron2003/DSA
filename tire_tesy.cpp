#include <bits/stdc++.h>
#include <iostream>
using namespace std;

class TrieNode
{
public:
    char data;
    TrieNode *children[26];
    bool terminated;

    TrieNode(char ch)
    {
        data = ch;
        for (int i = 0; i < 26; i++)
        {
            children[i] = NULL;
        }
        terminated = false;
    }
};

class Trie
{
public:
    TrieNode *root;

    Trie()
    {
        root = new TrieNode('\0');
    }

    void insertHelper(TrieNode *root, string word)
    {
        if (word.length() == 0)
        {
            root->terminated = true;
            return;
        }
        int index = word[0] - 'A';
        TrieNode *child;
        if (root->children[index] != NULL)
        {
            child = root->children[index];
        }
        else
        {
            child = new TrieNode(word[0]);
            root->children[index] = child;
        }
        insertHelper(child, word.substr(1));
    }

    void insertWord(string word)
    {
        transform(word.begin(), word.end(), word.begin(), ::toupper); // Ensure word is uppercase
        insertHelper(root, word);
    }

    bool searchHelper(TrieNode *root, string word)
    {
        if (word.length() == 0)
        {
            return root->terminated;
        }
        int index = word[0] - 'A';
        TrieNode *child;
        if (root->children[index] != NULL)
        {
            child = root->children[index];
        }
        else
        {
            return false;
        }
        return searchHelper(child, word.substr(1));
    }

    bool search(string word)
    {
        transform(word.begin(), word.end(), word.begin(), ::toupper); // Ensure word is uppercase
        return searchHelper(root, word);
    }

    bool deleteHelper(TrieNode *root, string word)
    {
        if (word.length() == 0)
        {
            if (root->terminated)
            {
                root->terminated = false;
                return isEmpty(root); // Return true if no children
            }
            return false;
        }
        int index = word[0] - 'A';
        TrieNode *child;
        if (root->children[index] == NULL)
        {
            return false;
        }
        child = root->children[index];
        bool shouldDeleteChild = deleteHelper(child, word.substr(1));
        if (shouldDeleteChild)
        {
            delete root->children[index];
            root->children[index] = NULL;
            return !root->terminated && isEmpty(root);
        }
        return false;
    }

    void deleteWord(string word)
    {
        transform(word.begin(), word.end(), word.begin(), ::toupper); // Ensure word is uppercase
        deleteHelper(root, word);
    }

    bool isEmpty(TrieNode *node)
    {
        for (int i = 0; i < 26; i++)
        {
            if (node->children[i] != NULL)
            {
                return false;
            }
        }
        return true;
    }
};

void testTrie()
{
    Trie *node = new Trie();
    node->insertWord("ABCD");
    node->insertWord("ABCDE");
    node->insertWord("ABCDT");
    node->deleteWord("ABCD");
    cout << (node->search("ABCD") ? "Found" : "Not Found") << endl;
    cout << (node->search("ABCDE") ? "Found" : "Not Found") << endl;
    cout << (node->search("ABCDT") ? "Found" : "Not Found") << endl;
}

int main()
{
    testTrie();
    return 0;
}
