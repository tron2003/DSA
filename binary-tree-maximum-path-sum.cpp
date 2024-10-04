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
    int dfs(tree *root, int &res)
    {

        if (!root)
        {
            return 0;
        }
        int left = max(0, dfs(root->left, res));
        int right = max(0, dfs(root->right, res));
        int curr = root->val + left + right;
        res = max(res, curr);
        return root->val + max(left, right);
    }
    int maxPathSum(TreeNode *root)
    {

        int res = INT_MIN;
        dfs(root, res);
        return res;
    }
};