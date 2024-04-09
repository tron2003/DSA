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

void func(Node *head)
{

    if (head==NULL)
    {
        return;
    }
    cout << head->val<<" ";
    func(head->left);
    func(head->right);
}
int main()
{

    Node *root = new Node(9000);
    root->left = new Node(20);
    root->right = new Node(30);
    func(root);

    return 0;
}