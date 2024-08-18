#include <bits/stdc++.h>
class node
{
public:
    node *arr[26];
    int countEnd;
    int countPrefix;
    void *put(char key, node *temp) { arr[key - 'a'] = temp; }
    bool contain(char key) { return arr[key - 'a'] != NULL; }
    node *get(char key) { return arr[key - 'a']; }

    void increasePrefix() { countPrefix++; }
    void increaseEnd() { countEnd++; }
    void decreaseprefix() { countPrefix--; }
    void decreaseEnd() { countEnd--; }
};

class Trie
{
private:
    node *root;

public:
    Trie()
    {
        root = new node();
        // Write your code here.
    }

    void insert(string &word)
    {
        // Write your code here.
        node *temp = root;
        for (int i = 0; i < word.size(); i++)
        {
            if (!temp->contain(word[i]))
            {

                temp->put(word[i], new node());
            }
            temp = temp->get(word[i]);
            temp->increasePrefix();
        }
        temp->increaseEnd();
    }

    int countWordsEqualTo(string &word)
    {

        // Write your code here.
        node *temp = root;
        for (int i = 0; i < word.size(); i++)
        {
            if (!temp->contain(word[i]))
            {

                return 0;
            }
            temp = temp->get(word[i]);
        }
        return temp->countEnd;
    }

    int countWordsStartingWith(string &word)
    {
        node *temp = root;
        for (int i = 0; i < word.size(); i++)
        {
            if (!temp->contain(word[i]))
            {

                return 0;
            }
            temp = temp->get(word[i]);
        }
        return temp->countPrefix;
    }

    void erase(string &word)
    {
        node *temp = root;
        for (int i = 0; i < word.size(); i++)
        {
            if (!temp->contain(word[i]))
            {

                return;
            }

            temp = temp->get(word[i]);
            temp->decreaseprefix();
        }

        temp->decreaseEnd();
    }
};
