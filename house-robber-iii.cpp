/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
#define tree TreeNode
class Solution
{
public:
    int helper(tree *root, int &left, int &right)
    {

        if (!root)
        {
            return 0;
        }
        int ll = 0, lr = 0, rr = 0, rl = 0;
        left = helper(root->left, ll, lr);
        right = helper(root->right, rr, rl);
        return max({root->val + ll + lr + rr + rl, left + right});
    }
    int rob(TreeNode *root)
    {
        int left = 0;
        int right = 0;
        return helper(root, left, right);
    }
};