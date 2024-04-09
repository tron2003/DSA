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

int func(Node *head)
{

    if (head == NULL)
    {
        return 0;
    }
    return max(func(head->left), func(head->right) )+1;
}
int main()
{

    Node *root = new Node(9000);
    root->left = new Node(20);
    root->right = new Node(30);
    // root->right->right=new Node(3434);
    cout<<func(root);

    return 0;
}