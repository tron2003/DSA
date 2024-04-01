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

    Node *es = NULL, *ee = NULL, *os = NULL, *oe = NULL;
    for (Node *curr = head; curr != NULL; curr = curr->next)
    {
        int x = curr->data;
        if (x % 2 == 0)
        {
            if (es == NULL)
            {

                es = curr;
                ee = curr;
            }
            else
            {

                ee->next = curr;
                ee = ee->next;
            }
        }
        else
        {
            if (os == NULL)
            {
                os = curr;
                oe = curr;
            }
            else
            {
                oe->next = curr;
                oe = oe->next;
            }
        }
    }
    if (es == NULL || os == NULL)
    {
        return head;
    }
    ee->next = os;
    oe->next = NULL;
    return es;
}

int main()
{

    Node *head = new Node(12);
    Node *temp = new Node(131);
    head->next = temp;
    temp = new Node(230);
    head->next->next = temp;
    temp = new Node(34);
    head->next->next->next = temp;

    head = func(head);

    // Print the reversed linked list
    Node *current = head;
    while (current != nullptr)
    {
        cout << current->data << " ";
        current = current->next;
    }

    return 0;
}