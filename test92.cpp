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
    if (!root)
    {
        return 0;
    }
    else{
    return 1+func(root->right)+func(root->right);

    }
    
    
}

int main()
{

    Node *root = new Node(9000);
    root->left = new Node(20);
    root->right = new Node(30);


    // Call the function to print nodes at distance 1 from the root
    cout << func(root);

    return 0;
}