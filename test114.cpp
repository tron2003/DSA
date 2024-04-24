#include <iostream>
#include <unordered_set>
using namespace std;

// Node structure for the binary tree
struct Node
{
    int val;
    Node *left;
    Node *right;
    Node(int value) : val(value), left(nullptr), right(nullptr) {}
};

// Function to check if there exist two distinct nodes in the binary tree whose values add up to the given sum
bool checksum(Node *root, int sum, unordered_set<int> &set)
{
    if (!root)
    {
        return false;
    }
    if (checksum(root->left, sum, set))
    {
        return true;
    }
    if (set.find(sum - root->val) != set.end())
    {
        return true;
    }
    else
    {
        set.insert(root->val);
    }
    return checksum(root->right, sum, set);
}

int main()
{
    // Creating a sample binary tree
    Node *root = new Node(10);
    root->left = new Node(5);
    root->right = new Node(15);
    root->left->left = new Node(3);
    root->left->right = new Node(7);
    root->right->left = new Node(12);
    root->right->right = new Node(17);

    int sum = 20;
    unordered_set<int> set;

    if (checksum(root, sum, set))
    {
        cout << "There exist two distinct nodes whose values add up to " << sum << endl;
    }
    else
    {
        cout << "There are no two distinct nodes whose values add up to " << sum << endl;
    }

    return 0;
}
