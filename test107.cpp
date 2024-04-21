#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define tree TreeNode
class TreeNode
{
public:
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};
tree *insert(tree *root, int x)
{

    if (!root)
    {
        return new tree(x);
    }
    if (root->val < x)
    {
        root->right = insert(root->right, x);
    }
    else
    {
        root->left = insert(root->left, x);
    }
    return root;
}

int main()
{
    tree *root = new TreeNode(5);
    root = insert(root, 3);
    root = insert(root, 8);
    root = insert(root, 1);
    root = insert(root, 4);
    root = insert(root, 7);
    // Print the tree to verify
    // Expected output: 5 -> 3 -> 1 -> nullptr -> nullptr -> 4 -> nullptr -> nullptr -> 8 -> 7 -> nullptr -> nullptr -> nullptr

    return 0;
}