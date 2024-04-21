
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

    tree *temp = new tree(x);
    tree *parent = nullptr;
    tree *curr = root;
    while (curr != nullptr)

    {

        parent = curr;

        if (curr->val <x)
        {
            curr = curr->right;
        }
        else if (curr->val > x)
        {
            curr = curr->left;
        }
        else
        {
            return root;
        }
    }
    if (parent == nullptr)
    {
        return temp;
    }
    else if (parent->val < x)
    {
        parent->right = temp;
    }
    else
    {
        parent->left = temp;
    }
    return root;
}

void printTree(tree *root)
{
    if (root)
    {
        printTree(root->left);
        cout << root->val << " -> ";
        printTree(root->right);
    }
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
    cout << "BST in-order traversal: ";
    printTree(root);
    cout << "nullptr" << endl;

    return 0;
}
