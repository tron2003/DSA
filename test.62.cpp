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

Node *reverseLinkedList(Node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    Node *prev = NULL;
    Node *curr = head;
    while (curr != NULL)
    {
        Node *temp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = temp;
    }
    return prev; // Return the new head of the reversed list
}

int main()
{
    Node *head = new Node(12);
    Node *temp = new Node(12);
    head->next = temp;
    temp = new Node(230);
    head->next->next = temp;
    temp = new Node(34);
    head->next->next->next = temp;

    // Reverse the linked list
    Node *reversedHead = reverseLinkedList(head);

    // Print the reversed linked list
    Node *current = reversedHead;
    while (current != NULL)
    {
        cout << current->data << " ";
        current = current->next;
    }

    return 0;
}
