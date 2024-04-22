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

tree *floor(tree *root, int x)
{

    if (!root)
    {
        return nullptr;
    }
    tree *res = nullptr; // Initialize res to nullptr
    while (root)
    {

        if (root->val == x)
        {
            return root;
        }
        else if ( x<root->val)
        {
            root = root->left;
        }
        else
        {
            res = root; // Update res to the current node before moving to the right subtree
            root = root->right;
        }
    }

    return res; // Return the last node where res was updated
}

void inorder(tree *root)
{
    if (root)
    {
        inorder(root->left);
        cout << root->val << " ";
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

    cout << "Original BST: ";
    inorder(root);
    cout << endl;

    // Test Case 1: Find the floor value of 35
    int key1 = 35;
    tree *floorNode1 = floor(root, key1);
    cout << "Floor value of " << key1 << " is: ";
    if (floorNode1)
        cout << floorNode1->val << endl;
    else
        cout << "No floor value found" << endl;

    // Test Case 2: Find the floor value of 65
    int key2 = 65;
    tree *floorNode2 = floor(root, key2);
    cout << "Floor value of " << key2 << " is: ";
    if (floorNode2)
        cout << floorNode2->val << endl;
    else
        cout << "No floor value found" << endl;

    // Test Case 3: Find the floor value of 10
    int key3 = 10;
    tree *floorNode3 = floor(root, key3);
    cout << "Floor value of " << key3 << " is: ";
    if (floorNode3)
        cout << floorNode3->val << endl;
    else
        cout << "No floor value found" << endl;

    return 0;
}
