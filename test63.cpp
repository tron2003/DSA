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

Node *dupl(Node *head)
{

    Node *curr = head;

    while (curr != NULL && curr->next != NULL)
    {

        if (curr->data == curr->next->data)
        {

            Node *temp = curr->next;
            curr->next = curr->next->next;
            delete (temp);
        }
        else
        {

            curr = curr->next;
        }
    }
}

int main()
{
    Node *head = new Node(12);
    Node *lis = head;
    Node *temp = new Node(12);
    head->next = temp;
    temp = new Node(230);
    head->next->next = temp;
    temp = new Node(34);
    head->next->next->next = temp;
    dupl(lis);
    while (lis != NULL)
    {
        cout << lis->data << " ";
        lis = lis->next;
    }
    return 0;
}
