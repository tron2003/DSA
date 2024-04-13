#include <iostream>
#include <queue>
using namespace std;

class TreeNode
{
public:
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

TreeNode *func(int arr1[], int arr2[], int l, int h, int &preindex)
{
    if (l > h)
    {
        return nullptr;
    }
    TreeNode *root = new TreeNode(arr2[preindex++]);
    if (l == h)
    {
        return root;
    }
    int inindex = 0;
    ;
    for (int i = l; i <=h; i++)
    {
        if (arr1[i] == root->val)
        {
            inindex = i;
            break;
        }
    }
    root->left = func(arr1, arr2, l, inindex - 1, preindex);
    root->right = func(arr1, arr2, inindex + 1, h, preindex);

    return root;
}
void printInorder(TreeNode *node)
{
    if (node == nullptr)
    {
        return;
    }
    printInorder(node->left);
    cout << node->val << " ";
    printInorder(node->right);
}
int main()
{
    int inorder[] = {4, 2, 5, 1, 6, 3, 7};
    int preorder[] = {1, 2, 4, 5, 3, 6, 7};
    int n = sizeof(inorder) / sizeof(inorder[0]);
    int preIndex = 0;

    TreeNode *root = func(inorder, preorder, 0, n - 1, preIndex);

    cout << "Inorder traversal of constructed tree:\n";
    printInorder(root);

    return 0;
}
