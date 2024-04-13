#include <iostream>
#include <queue>
using namespace std;

class ListNode {
public:
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class TreeNode {
public:
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

ListNode* convertBinaryTreeToLinkedList(TreeNode* root) {
    if (!root)
        return nullptr;

    ListNode* head = nullptr;
    ListNode* tail = nullptr;

    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        TreeNode* node = q.front();
        q.pop();

        // Create a new ListNode for the current TreeNode
        ListNode* newNode = new ListNode(node->val);

        // If it's the first node encountered, set it as head
        if (!head) {
            head = newNode;
            tail = newNode;
        } else {
            // Otherwise, append it to the tail
            tail->next = newNode;
            tail = newNode;
        }

        // Enqueue the left and right children of the current TreeNode
        if (node->left)
            q.push(node->left);
        if (node->right)
            q.push(node->right);
    }

    return head;
}

// Utility function to print the linked list
void printList(ListNode* head) {
    while (head != nullptr) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    ListNode* head = convertBinaryTreeToLinkedList(root);
    printList(head);

    return 0;
}
