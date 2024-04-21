#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define tree TreeNode
class TreeNode
{ public:
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};
bool search(tree*root,int x){

    if(!root){
        return false;
    }
    if(root->val==x){
        return true;
    }
    else if(root->val>x){
        return search(root->left, x);
    }else {
        return search(root->right, x);
    }
}

int main(){
    tree *root = new TreeNode(5);
    root->left = new TreeNode(-1 );
    root->right = new TreeNode(7);
    int x = 3;
    cout << "Searching for " << x << ": " << (search(root, x) ? "Found" : "Not found") << endl;

    return 0;
}