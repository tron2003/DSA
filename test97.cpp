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

int func(Node *root)
{
    if (root==nullptr)
    {
        return 0;
    }
    int lh = func(root->left);
    if (lh == -1)
    {
        return -1;
    }
    int rh = func(root->right);
    if (rh == -1)
    {
        return -1;
    }
    if (abs(lh - rh) > 1)
    {
        return -1;
    }
    else{

    return max(lh, rh) + 1;
    }
}

int main()
{
    Node *root = new Node(3);
    root->left = new Node(2);
    root->right = new Node(1);
    // root->left->left = new Node(1);
    // root->left->right = new Node(1);
    // root->right->left = new Node(1);
    root->right->left = new Node(22);
    root->left->right=new Node(12);
    // root->right->right->right->right=new Node(12);

    cout << func(root);

    return 0;
}
