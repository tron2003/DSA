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
    queue<Node *> que;
    if (!root)
    {
        return true;
    }
    que.push(root);

    while (!que.empty())
    {
        int n = que.size();
        
            int sum = 0;
            Node *curr = que.front();
            que.pop();
            if(curr->left==nullptr&&curr->right==nullptr){

                continue;
            }
            if (curr->left)
            {
                sum = sum + curr->left->val;
                que.push(curr->left);
            }
            if (curr->right)
            {
                sum = sum + curr->right->val;
                que.push(curr->right);
            }
            if (curr->val != sum &&sum !=0)
            {   
                return false;
            }
        
    }
    return true;
}

int main()
{
    Node *root = new Node(3);
    root->left = new Node(2);
    root->right = new Node(1);
    root->left->left = new Node(1);
    root->left->right = new Node(1);
    root->right->left = new Node(1);
    root->right->right = new Node(0);

    cout << boolalpha << func(root);

    return 0;
}
