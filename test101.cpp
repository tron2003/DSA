#include <iostream>
#include <algorithm>
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

tree *func(tree *root, int num1, int num2)
{

    if (!root)
    {
        return 0;
    }
    if (root->val == num1)
    {
        return root;
    }
    tree *lca1 = func(root->left, num1, num2);
    tree *lca2 = func(root->right, num1, num2);
    if (lca1 != nullptr && lca2 != nullptr)
    {
        return root;
    }
    if (lca1 == nullptr)
    {
        return lca2;
    }
    else
    {
        return lca1;
    }
}

int main()
{
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    // Test Case 1: Basic Case
    tree *ancestor1 = func(root, 4, 5);
    cout << "LCA of 4 and 5: " << ancestor1->val << endl; // Expected: 2

    // Test Case 2: Nodes Not Present
    tree *ancestor2 = func(root, 4, 6);
    if (ancestor2 == nullptr)
        cout << "Nodes not found in the tree" << endl;
    else
        cout << "LCA of 4 and 6: " << ancestor2->val << endl; // Expected: Nodes not found in the tree

    // Test Case 3: Nodes at Different Levels
    tree *ancestor3 = func(root, 4, 3);
    cout << "LCA of 4 and 3: " << ancestor3->val << endl; // Expected: 1

    // Test Case 4: Nodes are the Same
    tree *ancestor4 = func(root, 4, 4);
    cout << "LCA of 4 and 4: " << ancestor4->val << endl; // Expected: 4

    // Test Case 5: Empty Tree
    tree *ancestor5 = func(nullptr, 4, 5);
    if (ancestor5 == nullptr)
        cout << "Empty tree" << endl; // Expected: Empty tree
    else
        cout << "LCA of 4 and 5: " << ancestor5->val << endl;

    return 0;
}
