#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int val;
    Node *left;
    Node *right;
    Node(int x)
    {
        val = x;
        left = right = nullptr;
    }
};

void func(Node *root, vector<int> &res)
{

    queue<Node *> que;
    if (!root)
    {
        return;
    }
    que.push(root);

    while (!que.empty())
    {

        int n = que.size();
        for (int i = 0; i < n; i++)
        {
            Node *curr = que.front();
            if (i == 0)
            {

                res.push_back(curr->val);
            }
            que.pop();
            if (curr->left)
            {
                que.push(curr->left);
            }
            if (curr->right)
            {

                que.push(curr->right);
            }
        }
    }
}

int main()
{

    Node *root = new Node(9);
    root->left = new Node(20);
    root->right = new Node(30);

    // Adding depth to the left subtree

    root->left->right = new Node(50);

    // Adding depth to the right subtree
    root->right->left = new Node(60);
    root->right->right = new Node(70);

    // root->left->left->right = new Node(90);

    // Adding more depth to the right subtree
    root->right->right->left = new Node(100);
    root->right->right->right = new Node(110);

    vector<int> res;
    func(root, res);
    for (auto x : res)
    {
        cout << x << " ";
    }

    return 0;
}