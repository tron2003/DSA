#include <bits/stdc++.h>

class Node
{

public:
    Node *links[26];

    bool flag = false;
};

string longestCommonPrefix(vector<string> &arr, int n)

{
    Node *node = new Node();

    string a = arr[0];

    Node *root = node;

    for (int i = 0; i < a.size(); i++)
    {

        root->links[a[i] - 'a'] = new Node();

        root = root->links[a[i] - 'a'];
    }

    int mn = INT_MAX;

    for (int i = 1; i < arr.size(); i++)
    {

        Node *root = node;

        string temp = arr[i];

        int t = 0;

        for (int j = 0; j < temp.size(); j++)
        {

            if (root->links[temp[j] - 'a'] == NULL)
            {

                break;
            }

            else
            {

                root = root->links[temp[j] - 'a'];

                t++;
            }
        }

        mn = min(mn, t);
    }

    return arr[0].substr(0, mn);
}