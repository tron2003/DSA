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

Node *func(Node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    Node *dummy = new Node(0);
    dummy->next = head;
    Node *prev = dummy;

    while (prev->next && prev->next->next)
    {
        Node *first = prev->next;
        Node *second = prev->next->next;

        first->next = second->next;
        second->next = first;
        prev->next = second;

        prev = first;
    }
    return dummy->next;
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