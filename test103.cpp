#include <iostream>
#include <vector>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

TreeNode *countNodes(vector<int> &arr, int &idx)
{
    if (idx == arr.size()  )
    {
       
        return nullptr;
    }
    int val = arr[idx++];
   
    TreeNode *root = new TreeNode(val);
    root->left = countNodes(arr, idx);
    root->right = countNodes(arr, idx);
    return root;
}

int countNodes(TreeNode *root)
{
    if (root == nullptr)
    {
        return 0;
    }
    return 1 + countNodes(root->left) + countNodes(root->right);
}

int main()
{
    vector<int> arr = {1, 2, 3, 4, 5, NULL, 6};
    int idx = 0;
    TreeNode *root = countNodes(arr, idx);

    // Call the countNodes function and print the result
    cout << "Number of nodes in the binary tree: " << countNodes(root) << endl;

    // Deallocate memory
    // Your code for deallocation here

    return 0;
}
