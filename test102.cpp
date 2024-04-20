#include<iostream>
#include<bits/stdc++.h>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};
int countNodes(TreeNode *root)
{
    if (root == nullptr)
        return 0;

    int lh = 0;
    int rh = 0;
    TreeNode *curr = root;

    while (curr)
    {
        lh++;
        curr = curr->left;
    }

    curr = root;
    while (curr)
    {
        rh++;
        curr = curr->right;
    }

    if (lh == rh)
    {
        return pow(2, lh) - 1;
    }

    return 1 + countNodes(root->left) + countNodes(root->right);
}
int main()
{
    // Create a sample binary tree
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);

    // Call the countNodes function and print the result
    cout << "Number of nodes in the binary tree: " << countNodes(root) << endl;

    // Don't forget to deallocate memory
    delete root->left->left;
    delete root->left->right;
    delete root->right->left;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}
