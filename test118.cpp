#include <iostream>
#include <bits/stdc++.h>
#include <unordered_map>
#include <vector>
// #include <pair>
using namespace std;

struct Node
{
    int val;
    Node *left;
    Node *right;
    Node(int value) : val(value), left(nullptr), right(nullptr) {}
};
void sumr(Node *root, int h, unordered_map<int, vector<int>> &mp)
{

    queue<pair<Node *, int>> que;
    que.push({root, h});
    while (!que.empty())
    {

        auto num1 = que.front();
        auto nu2 = num1.first;
        auto nu3 = num1.second;
        mp[nu3].push_back(nu2->val);
        que.pop();

        if (nu2->left)
        {
            que.push({nu2->left, nu3 - 1});
        }
        if (nu2->right)
        {
            que.push({nu2->right, nu3 + 1});
        }
    }
}
void sum(Node *root)
{
    unordered_map<int, vector<int>> mp;
    sumr(root, 0, mp);
    for (auto x : mp)
    {
        int n = x.second.size();
        cout << x. second[n-1];
        
        cout << endl;
    }
}

int main()
{
    // Test Case 1
    // Creating a sample binary tree
    Node *root1 = new Node(1);
    root1->left = new Node(2);
    root1->right = new Node(3);
    root1->left->left = new Node(4);
    root1->left->right = new Node(5);
    root1->right->left = new Node(6);
    root1->right->right = new Node(7);

    cout << "Vertical  nodes for Test Case 1: ";
    sum(root1);
    cout << endl;

    // // Test Case 2
    // // Creating another sample binary tree
    // Node *root2 = new Node(5);
    // root2->left = new Node(2);
    // root2->right = new Node(7);
    // root2->left->left = new Node(1);
    return 0;
}
