#include <iostream>
#include <climits>
using namespace std;

// Node structure for the binary tree
struct Node
{
    int val;
    Node *left;
    Node *right;
    Node(int value) : val(value), left(nullptr), right(nullptr) {}
};

// Global variable to store the previous value during traversal
int prevValue = INT_MIN;

// Function to check if the binary tree is a Binary Search Tree (BST)
bool isBST(Node *root)
{
    if (!root)
    {
        return true;
    } 
    if (!isBST(root->left))
    {
        return false;
    }
    if (root->val <= prevValue)
    {
        return false;
    }
    prevValue = root->val;
    return isBST(root->right);
}

// Function to create a sample binary tree
Node *createBST()
{
    Node *root = new Node(4);
    root->left = new Node(2);
    root->right = new Node(6);
    root->left->left = new Node(1);
    root->left->right = new Node(3);
    root->right->left = new Node(5);
    root->right->right = new Node(7);
    return root;
}

int main()
{
    Node *root = createBST();

    cout << "Is the binary tree a BST? " << (isBST(root) ? "Yes" : "No") << endl;

    // Test cases
    // Modify the binary tree structure or create new test cases as needed

    return 0;
}
