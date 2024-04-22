
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
inline tree *getsuccesor(tree *root)
{

    tree *curr = root;
    while (curr && curr->left)
    {
        curr = curr->left;
    }
    return curr;
}
tree *deletenode(tree *root, int x)
{

    if (!root)
    {
        return root;
    }
    else if (root->val > x)
    {
        root->left = deletenode(root->left, x);
    }
    else if (root->val < x)
    {
        root->right = deletenode(root->right, x);
    }
    else
    {
        if (root->left == nullptr)
        {
            tree *temp = root;
            root = root->right;
            delete temp;
        }
        else if (root->right == nullptr)
        {
            tree *temp = root;
            root = root->left;
            delete temp;
        }
        else
        {
            tree *succ = getsuccesor(root->right);
            root->val = succ->val;
            root->right = deletenode(root->right, succ->val);
        }
    }
    return root;
}
void inorder(tree *root){
    if(root){
        cout << root->val << " ";
        inorder(root->left);
        inorder(root->right);
    }
}
int main()
{
    TreeNode *root = new TreeNode(50);
    root->left = new TreeNode(30);
    root->right = new TreeNode(70);
    root->left->left = new TreeNode(20);
    root->left->right = new TreeNode(40);
    root->right->left = new TreeNode(60);
    root->right->right = new TreeNode(80);

    cout << "Original Tree: ";
    inorder(root);
    cout << endl;

    // Test Case 1: Delete a leaf node (20)
    root = deletenode(root, 20);
    cout << "After deleting 20: ";
    inorder(root);
    cout << endl;

    // Test Case 2: Delete a node with one child (70)
    root = deletenode(root, 70);
    cout << "After deleting 70: ";
    inorder(root);
    cout << endl;

    // Test Case 3: Delete a node with two children (50)
    root = deletenode(root, 50);
    cout << "After deleting 50: ";
    inorder(root);
    cout << endl;

    return 0;
}
