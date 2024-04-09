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

void func(Node *root, int k)
{

    if (root == NULL)
    {
        return;
    }
    if (k == 0)
    {
        cout << root->val << " ";
    }
    else
    {
        func(root->left, k - 1);
        func(root->right, k - 1);
    }
}
int main()
{

    Node *root = new Node(9000);
    root->left = new Node(20);
    root->right = new Node(30);

    // Adding depth to the left subtree
    root->left->left = new Node(40);
    root->left->right = new Node(50);

    // Adding depth to the right subtree
    root->right->left = new Node(60);
    root->right->right = new Node(70);

    // Adding more depth to the left subtree
    root->left->left->left = new Node(80);
    root->left->left->right = new Node(90);

    // Adding more depth to the right subtree
    root->right->right->left = new Node(100);
    root->right->right->right = new Node(110);

    // Call the function to print nodes at distance 1 from the root
    func(root, 1);

    return 0;
}