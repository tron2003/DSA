#include <iostream>
#include <vector>
#include <queue>
#include <string>

using namespace std;

// Node structure
struct node {
    int freq;
    char ch;
    node *left, *right;
    node(char c, int f, node *l = nullptr, node *r = nullptr) {
        freq = f;
        ch = c;
        left = l;
        right = r;
    }
};

// Comparator for priority queue
struct compare {
    bool operator()(node* a, node* b) {
        return a->freq > b->freq; // Correct comparator for min-heap
    }
};

// Function to print Huffman codes
void printcode(node* root, string str) {
    if (!root) return;
    if (root->ch != '$') {
        cout << root->ch << ": " << str << endl;
    }
    printcode(root->left, str + "0");
    printcode(root->right, str + "1");
}

// Function to build Huffman tree and print codes
void func(vector<char> arr1, vector<int> arr2, int n) {
    priority_queue<node*, vector<node*>, compare> que;

    for (int i = 0; i < n; i++) {
        que.push(new node(arr1[i], arr2[i]));
    }

    while (que.size() > 1) {
        node *l = que.top(); que.pop();
        node *r = que.top(); que.pop();
        node *temp = new node('$', l->freq + r->freq, l, r);
        que.push(temp);
    }

    printcode(que.top(), "");
}

int main() {
    vector<char> arr1 = {'a', 'b', 'c', 'd', 'e', 'f'};
    vector<int> arr2 = {5, 9, 12, 13, 16, 45};
    int n = arr1.size();

    func(arr1, arr2, n);

    return 0;
}
