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

int func(Node *curr, Node *curr2)
{
    while (curr != NULL && curr2 != NULL)
    {

        if (curr == curr2)
        {
            return curr->data;
        }
        curr = curr->next;
        curr2 = curr2->next;
    }
    return -1;
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

    int res = func(head, head2);
    cout << res;
    return 0;
}