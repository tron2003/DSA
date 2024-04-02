#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *random;                                            // Added random pointer
    Node(int d) : data(d), next(nullptr), random(nullptr) {} // Constructor initialization list
};

Node *func(Node *h1)
{
    // Step 1: Clone each node and insert it after the original node
    Node *curr = h1;
    while (curr)
    {
        Node *Next = curr->next;
        curr->next = new Node(curr->data); // Create a new node with the same data
        curr->next->next = Next;
        curr = Next;
    }

    // Step 2: Adjust the random pointers of cloned nodes
    for (Node *curr = h1; curr != NULL; curr = curr->next->next)
    {
        // Set the random pointer of cloned node to the corresponding node in the cloned list
        curr->next->random = (curr->random == NULL) ? NULL : curr->random->next;
    }

    // Step 3: Split the combined list into two separate lists
    Node *h2 = h1->next;
    Node *clone = h2;
    for (Node *curr = h1; curr != NULL; curr = curr->next)
    {
        curr->next = curr->next->next;                        // Adjust original list's next pointers
        clone->next = clone->next ? clone->next->next : NULL; // Adjust cloned list's next pointers
        clone = clone->next;
    }

    return h2; // Return the head of the cloned list
}

int main()
{

    Node *head = new Node(12);
    Node *temp = new Node(131);
    head->next = temp;
    Node *temp1 = new Node(230);
    head->next->next = temp1;
    temp = new Node(34);
    head->next->next->next = temp;

    Node *head2 = new Node(32);
    head2->next = temp1;

    Node *res = func(head);
    while (res != NULL)
    {
        cout << (res->data) << " ";
        res = res->next;
    }

    return 0;
}
