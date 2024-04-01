#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Node
{

public:
    int data;
    Node *next;
    Node(int d)
    {
        data = d;
        next = nullptr;
    }
};

void func(Node *head)
{
    Node *slow = head;
    Node *fast = head;
    while (fast != nullptr && fast->next != nullptr)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
        {

            break;
        }
    }
    if (slow != fast)
    {

        return;
    }
    slow = head;
    while (slow->next != fast->next)
    {

        slow = slow->next;
        fast = fast->next;
    }
    fast->next = nullptr;
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
    func(head);

    // Print the reversed linked list
    Node *current = head;
    while (current != nullptr)
    {
        cout << current->data << " ";
        current = current->next;
    }

    return 0;
}