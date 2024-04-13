#include <iostream>
#include <algorithm>
using namespace std;

class TreeNode {
public:
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

int height(TreeNode* root, int& diameter) {
    if (root == nullptr)
        return 0;
    
    int left_height = height(root->left, diameter);
    int right_height = height(root->right, diameter);
    
    // Update diameter if the sum of left and right heights is greater
    diameter = max(diameter, left_height + right_height);
    
    // Return height of current subtree
    return 1 + max(left_height, right_height);
}

int diameterOfBinaryTree(TreeNode* root) {
    int diameter = 0;
    height(root, diameter);
    return diameter;
}

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    
    cout << "Diameter of the binary tree: " << diameterOfBinaryTree(root) << endl;

    return 0;
}
