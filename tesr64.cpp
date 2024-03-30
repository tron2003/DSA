#include <iostream>
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node(int d)
    {
        data = d;
        next = nullptr;
    }
};

Node *reversek(Node *head, int k)
{
    Node *curr = head;
    Node *prev = nullptr;
    Node *next = nullptr;
    int count = 0;

    // Reverse first k nodes of the linked list
    while (curr != nullptr && count < k)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
        count++;
    }

    // If there are remaining nodes, recursively reverse them
    if (next != nullptr)
    {
        head->next = reversek(next, k);
    }

    // prev is the new head of the reversed group
    return prev;
}

int main()
{
    Node *head = new Node(12);
    Node *temp = new Node(132);
    head->next = temp;
    temp = new Node(230);
    head->next->next = temp;
    temp = new Node(34);
    head->next->next->next = temp;

    int k = 2; // Group size for reversal

    // Reverse the linked list in groups of size k
    Node *reversedHead = reversek(head, k);

    // Print the reversed linked list
    Node *current = reversedHead;
    while (current != nullptr)
    {
        cout << current->data << " ";
        current = current->next;
    }

    return 0;
}
