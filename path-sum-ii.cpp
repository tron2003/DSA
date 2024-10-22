/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */

#define tree TreeNode
class Solution
{
public:
    bool helper(tree *root, int sum, int tar, vector<int> &temp,
                vector<vector<int>> &res)
    {

        if (root == nullptr)
        {
            return false;
        }

        tree *x = root;
        temp.push_back(root->val);
        if (root->left == nullptr && root->right == nullptr &&
            sum + root->val == tar)
        {
            res.push_back(temp);
        }
        helper(root->left, sum + root->val, tar, temp, res);

        helper(root->right, sum + root->val, tar, temp, res);

        temp.pop_back();

        return false;
    }
    vector<vector<int>> pathSum(TreeNode *root, int tar)
    {

        vector<vector<int>> res;
        vector<int> temp;

        helper(root, 0, tar, temp, res);

        return res;
    }
};